#include <stdio.h>

int main(void)
{
	double rad;
	double area;
	printf("���� ������ �Է�: ");
	scanf_s("%lf", &rad);

	area = rad * 3.14195f;
	printf("���� ����: %f\n", area);

	return 0;
}