#include <stdio.h>
#include <tchar.h>
#include <windows.h>

// BELOW_NORMAL_PRIORITY_CLASS
// IDLE_PRIORITY_CLASS ���� ���� NORMAL_PRIORITY_CLASS ���� ���� �켱����
// �� Windows NT and Me ���� �������� �ʴ� �켱����
int _tmain(int argc, TCHAR* argv)
{
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);		// Busy Waiting!!

		_fputts(_T("BELOW_NORMAL_PRIORITY_CLASS Process\n"), stdout);
	}

	return 0;
}