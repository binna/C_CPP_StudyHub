#include <stdio.h>

int main(void)
{
	char name[10];
	char sex;
	int age, i;

	FILE* fp;

	fopen_s(&fp, "friend.txt", "wt");

	if (fp == NULL)
	{
		puts("���� ���� ����!");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		printf("�̸� ���� ���� �� �Է� : ");
		scanf_s("%s %c %d", name, sizeof(name), &sex, sizeof(char), &age);
		getchar();		// ���ۿ� �����ִ� \n�� �Ҹ��� ���Ͽ�
		fprintf(fp, "%s %c %d", name, sex, age);
	
	}

	fclose(fp);
	return 0;
}