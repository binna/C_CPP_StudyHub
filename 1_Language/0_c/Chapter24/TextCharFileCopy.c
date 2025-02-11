#include <stdio.h>

int main(void)
{
	FILE* src, * des;
	int ch;

	fopen_s(&src, "src.txt", "rt");
	fopen_s(&des, "des.txt", "wt");

	if (src == NULL || des == NULL)
	{
		puts("���� ���� ����!");
		return -1;
	}

	while ((ch = getc(src)) != EOF)
		fputc(ch, des);

	if (feof(src) != 0)
		puts("���� ���� �Ϸ�");
	else
		puts("���� ���� ����!");

	fclose(src);
	fclose(des);
	return 0;
}