#include <stdio.h>

int main(void)
{
	FILE* fp;
	fopen_s(&fp, "data.txt", "wt");

	if (fp == NULL)
	{
		printf("���� ���� ����");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	
	fclose(fp);
	return 0;
}