#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	strcpy_s(str2, sizeof(str2), str1);
	puts(str2);

	//errno_t strncpy_s(
	// char* strDest, size_t numberOfElements, 
	// const char* strSource, size_t count);
	//   strDest : ��� ���ڿ�
	//   numberOfElements : ��� ���ڿ��� ũ��(����)
	//   strSource : �ҽ� ���ڿ�
	//   count : ������ ���� ��
	//           ������ ���ڼ��� ������ ��, NULL ���� �ʿ�
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3) - 1);
	puts(str3);
	
	return 0;
}