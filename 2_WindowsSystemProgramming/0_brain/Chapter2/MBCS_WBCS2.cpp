#define UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	LPCTSTR str1 = _T("MBCS of WBCS 1");
	TCHAR str2[] = _T("MBCS of WBCS 2");
	TCHAR str3[100] = { 0 };
	TCHAR str4[50] = { 0 };

	LPCTSTR pStr = str1;

	_tprintf(_T("string size: %d\n"), sizeof(str2));
	_tprintf(_T("string length: %d\n"), _tcslen(pStr));

	_fputts(_T("Input String 1 : "), stdout);
	_tscanf_s(_T("%s"), str3, _countof(str3));
	_fputts(_T("Input String 2 : "), stdout);
	_tscanf_s(_T("%s"), str4, _countof(str4));

	_tcscat_s(str3, _countof(str3), str4);
	_tprintf(_T("String 1 + String 2 : %s\n"), str3);

	return 0;
}