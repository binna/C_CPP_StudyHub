#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define MAX_STRING_NUM	100
#define MAX_STRING_LEN	256

TCHAR stringArr[MAX_STRING_NUM][MAX_STRING_LEN];

void SortString(void);

int _tmain()
{
	SortString();

	return 0;
}

void SortString(void)
{
	// �ַܼκ��� ���ڿ��� �о� ���δ�
	int nStr;
	for (nStr = 0; nStr < MAX_STRING_NUM; nStr++)
	{
		TCHAR* isEOF = _fgetts(stringArr[nStr], MAX_STRING_LEN, stdin);

		if (isEOF == NULL)		// EOF�� Ctrl + Z
			break;
	}

	// String Bubble Sort
	// ���� ������� �ʰ� ���ڿ� ���� ����
	TCHAR strTemp[MAX_STRING_LEN];

	for (int i = 0; i < nStr; i++)
	{
		for (int j = nStr - 1; j > i; j--)
		{
			if (_tcscmp(stringArr[j - 1], stringArr[j]) > 0)
			{
				_tcscpy_s(strTemp, stringArr[j - 1]);
				_tcscpy_s(stringArr[j - 1], stringArr[j]);
				_tcscpy_s(stringArr[j], strTemp);
			}
		}
	}

	for (int i = 0; i < nStr; i++)
		_fputts(stringArr[i], stdout);
}