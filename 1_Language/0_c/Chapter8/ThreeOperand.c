#include <stdio.h>

int main(void)
{
	int num, abs;
	printf("���� �Է� : ");
	scanf_s("%d", &num);

	abs = num > 0 ? num : num * (-1);
	printf("���밪 : %d", abs);

	return 0;
}