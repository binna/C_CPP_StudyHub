#include <stdio.h>

#define STRING_JOB(A, B)	 #A"�� ������ " B"�Դϴ�."

int main(void)
{
	printf("%s\n", STRING_JOB("shine", "���� ������"));
	printf("%s\n", STRING_JOB('S', "���� ������"));
	printf("%s\n", STRING_JOB(94, "���� ������"));

	return 0;
}