#include <stdio.h>

int main(void)
{
	int num = 3;

	num = num << 3;		// 8�� ��
	num = num >> 2;		// 4�� ������

	printf("%d\n", num);

	return 0;
}