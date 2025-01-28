#include <tchar.h>
#include <windows.h>

// ABOVE_NORMAL_PRIORITY_CLASS
// NORMAL_PRIORITY_CLASS ���� ���� HIGH_PRIORITY_CLASS ���� ���� �켱����
// �� Windows NT and Me ���� �������� �ʴ� �켱����
int _tmain(int argc, TCHAR* argv)
{
	STARTUPINFO siNORMAL = { 0, };
	PROCESS_INFORMATION piNORMAL;
	TCHAR commandOne[] = _T("exe/NORMAL_PRIORITY_CLASS.exe");

	STARTUPINFO siBELOW = { 0, };
	PROCESS_INFORMATION piBELOW;
	TCHAR commandTwo[] = _T("exe/BELOW_NORMAL_PRIORITY_CLASS.exe");

	siNORMAL.cb = sizeof(siNORMAL);
	siBELOW.cb = sizeof(siBELOW);

	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);


	CreateProcess(NULL, commandOne, NULL, NULL, TRUE, 0, NULL, NULL, &siNORMAL, &piNORMAL);
	CreateProcess(NULL, commandTwo, NULL, NULL, TRUE, 0, NULL, NULL, &siBELOW, &piBELOW);

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);		// Busy Waiting!!

		_fputts(_T("ABOVE_NORMAL_PRIORITY_CLASS Process\n"), stdout);
	}

	return 0;
}