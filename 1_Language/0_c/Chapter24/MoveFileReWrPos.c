#include <stdio.h>

int main(void)
{
	// ���� ����
	FILE* fp, *fp2;

	fopen_s(&fp, "test.txt", "wt");
	
	if (fp == NULL)
	{
		printf("���� ���� ���� - 1");
		return -1;
	}

	fputs("123456789", fp);
	fclose(fp);

	// ���� ����
	fopen_s(&fp2, "test.txt", "rt");

	if (fp2 == NULL)
	{
		printf("���� ���� ���� - 2");
		return -1;
	}

	// SEEK_END test
	fseek(fp2, -2, SEEK_END);
	putchar(fgetc(fp2));

	// SEEK_SET test
	fseek(fp2, 2, SEEK_SET);
	putchar(fgetc(fp2));


	// SEEK_CUR test
	fseek(fp2, 2, SEEK_CUR);
	putchar(fgetc(fp2));

	fclose(fp2);

	return 0;
}