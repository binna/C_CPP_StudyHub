#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20];
	char str2[20];

	printf("���ڿ� �Է� 1 : ");
	scanf_s("%s", str1, 20);

	printf("���ڿ� �Է� 2 : ");
	scanf_s("%s", str2, 20);

	str1[19] = 0;
	str2[19] = 0;

	if (strcmp(str1, str2) == 0)
	{
		puts("�� ���ڿ��� �Ϻ��� �����մϴ�.");
	}
	else
	{
		puts("�� ���ڿ��� �������� �ʽ��ϴ�.");

		if (strncmp(str1, str2, 3) == 0)
			puts("�׷��� �� �����ڴ� �����մϴ�.");
	}

	return 0;
}