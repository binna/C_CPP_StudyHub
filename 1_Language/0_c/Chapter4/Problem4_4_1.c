#include <stdio.h>

int main(void)
{
	int num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	num = ~num + 1;

	printf("��ȣ�� �ٲ� ���: %d", num);

	return 0;
}