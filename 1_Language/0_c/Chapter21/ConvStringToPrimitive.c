#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[20] = { 0, };

	printf("���� �Է�: ");
	scanf_s("%s", str, sizeof(str));
	printf("%d\n", atoi(str));

	printf("�Ǽ� �Է�: ");
	scanf_s("%s", str, sizeof(str));
	printf("%f\n", atof(str));

	return 0;
}