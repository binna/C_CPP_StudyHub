#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define BUF_SIZE		1024

int CommToClient(HANDLE);

int _tmain(int argc, TCHAR* argv[])
{
	LPCWSTR pipeName = _T("\\\\.\\pipe\\simple_pipe");
	HANDLE hPipe;

	while (1)
	{
		// 1. ������ ����
		hPipe = CreateNamedPipe(
			pipeName,					// ���̺� �̸�
			PIPE_ACCESS_DUPLEX,			// �б�, ���� ��� ����
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 
			PIPE_UNLIMITED_INSTANCES,	// �ִ� ������ ����
			BUF_SIZE,					// ��� ���� ������
			BUF_SIZE,					// �Է� ���� ������
			20000,						// Ŭ���̾�Ʈ Ÿ�� �ƿ�
			NULL);						// ����Ʈ ���� �Ӽ�

		if (hPipe == INVALID_HANDLE_VALUE)
		{
			_tprintf(_T("CreatePipe failed"));
			return -1;
		}

		// 2. Ŭ���̾�Ʈ ���� ���
		BOOL isSuceess = 0;
		isSuceess = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

		if (isSuceess)
		{
			// 3-1. Ŭ���̾�Ʈ�� ��� ����
			CommToClient(hPipe);
		}
		else
		{
			// 3-2. ���� ���� �� ������ �ڵ� �ݱ�
			CloseHandle(hPipe);
		}
	}

	return 1;
}

// Ŭ���̾�Ʈ���� ����� ó���ϴ� �Լ�
int CommToClient(HANDLE hPipe)
{
	TCHAR fileName[MAX_PATH + 1] = { 0 };
	TCHAR dataBuf[BUF_SIZE + 1];

	BOOL isSuccess;
	DWORD fileNameSize;

	// (1) Ŭ���̾�Ʈ�κ��� ���� �̸� ����
	isSuccess = ReadFile(
		hPipe,						// ������ �ڵ�
		fileName,					// ���� �����͸� �����ϴ� ���ۿ� ���� ������ -> read ���� ����
		MAX_PATH * sizeof(TCHAR),	// ���� �� �ִ� �ִ� ����Ʈ �� -> read ���� ������
		&fileNameSize,				// ���� ����Ʈ ���� �޴� ������ ���� ������ -> ������ ������ ũ��
		NULL
	);

	if (!isSuccess || fileNameSize == 0)
	{
		_tprintf(_T("Pipe read message error!\n"));
		return -1;
	}

	// ���ڿ��� ���� �� ���� �߰�
	fileName[fileNameSize / sizeof(TCHAR)] = 0;


	// (2) Ŭ���̾�Ʈ�κ��� ���� ���� �̸����� ���� ����
	FILE* filePtr;

	errno_t errorNo = _tfopen_s(&filePtr, fileName, _T("r"));

	if (errorNo != 0 || filePtr == NULL)
	{
		_tprintf(_T("File open fault!/errorNo : %d/%s\n"), errorNo, fileName);
		return -1;
	}


	DWORD bytesWritten = 0;
	DWORD bytesRead = 0;
	int fileSize;
	size_t bytesToRead;

	// ���� ũ�� ���
	fseek(filePtr, 0, SEEK_END);
	fileSize = ftell(filePtr);
	rewind(filePtr);	// ���� �����͸� �ٽ� ���� ��ġ�� �̵�
	
	// (3) ���� ������ �о� Ŭ���̾�Ʈ�� ����
	while (fileSize > 0)
	{
		bytesToRead = (fileSize < BUF_SIZE) ? fileSize : BUF_SIZE;

		bytesRead = fread(dataBuf, 1, bytesToRead, filePtr);

		if (bytesRead > 0)
		{
			dataBuf[bytesRead / sizeof(TCHAR)] = 0;

			_tprintf(_T("Sending to client: %s\n"), dataBuf);

			WriteFile(
				hPipe,
				dataBuf,
				bytesRead,
				&bytesWritten,
				NULL);

			if (bytesRead != bytesWritten)
			{
				_tprintf(_T("Pipe write message error!\n"));
				break;
			}

			fileSize -= bytesRead;
		}
		else
		{
			_tprintf(_T("Failed to read file!\n"));
			break;
		}
	}

	FlushFileBuffers(hPipe);
	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
	return 1;
}