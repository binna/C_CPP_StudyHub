#include <stdio.h>

int main(void)
{
	FILE* src, * des;
	char str[20];

	fopen_s(&src, "src.txt", "rt");
	fopen_s(&des, "des.txt", "wt");

	if (src == NULL || des == NULL)
	{
		puts("���� ���� ����!");
		return -1;
	}

	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);

	if (feof(src) != 0)
		puts("���� ���� �Ϸ�");
	else
		puts("���� ���� ����!");

	fclose(src);
	fclose(des);
	return 0;
}