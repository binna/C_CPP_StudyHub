#include <stdio.h>

int main(void)
{
	char str1[] = "My String-1";	// ���� ������ ���ڿ�
	char* str2 = "My String-2";		// ��� ������ ���ڿ�
	printf("%s %s\n", str1, str2);

	str2 = "Our String";			// ����Ű�� ��� ����
	printf("%s %s\n", str1, str2);

	str1[0] = 'x';					// ���ڿ� ���� ����
	//str2[0] = 'x';					// ���ڿ� ���� ����
	printf("%s %s\n", str1, str2);

	return 0;
}