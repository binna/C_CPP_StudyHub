#include <stdio.h>

int main(void)
{
	double num1, num2;
	printf("�� ���� �Ǽ� �Է�: ");
	scanf_s("%lf %lf", &num1, &num2);

	printf("�� ���� ����: %f\n", num1 + num2);
	printf("�� ���� ����: %f\n", num1 - num2);
	printf("�� ���� ����: %f\n", num1 * num2);
	printf("�� ���� ������: %f\n", num1 / num2);
}