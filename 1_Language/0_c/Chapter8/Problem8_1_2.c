#include <stdio.h>

int main(void)
{
	int num1, num2;
	int result;

	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 < num2)
		result = num1 - num1;
	else
		result = num1 - num2;

	printf("������ ��� : %d", result);

	return 0;
}