#include <stdio.h>
#include <windows.h>

int main(void)
{
	char str[50];
	int idx = 0;

	printf("���ڿ� �Է�: ");
	scanf_s("%s", str, (unsigned int)_countof(str));		// ���ڿ��� �Է� �޾Ƽ� �迭 str�� ����

	printf("���� ���� ���: ");
	while (str[idx] != '\0')	// ���ڿ� ������ ���
	{
		printf("%c", str[idx]);
		idx++;
	}
	printf("\n");

	return 0;
}