#include <stdio.h>

int main(void)
{
	FILE* fp;
	fopen_s(&fp, "simple.txt", "wt");

	if (fp == NULL)
	{
		printf("���� ���� ����");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);

	fputs("I'm Hong\n", fp);
	fputs("you're Yoon\n", fp);

	fclose(fp);
	return 0;
}