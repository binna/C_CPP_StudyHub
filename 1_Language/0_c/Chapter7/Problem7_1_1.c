#include <stdio.h>

int main(void)
{
	int num;
	int i = 0;

	printf("���� ���� �Է� : ");
	scanf_s("%d", &num);

	while (i < num)
	{
		printf("Hello world!\n");
		i++;
	}
	return 0;
}