#include <stdio.h>

int main(void)
{
	int result, num1, num2;

	printf("���� 1 : ");
	scanf_s("%d", &num1);
	printf("���� 2 : ");
	scanf_s("%d", &num2);

	result = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, result);
	return 0;
}