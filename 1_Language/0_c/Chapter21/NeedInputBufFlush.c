#include <stdio.h>

int main(void)
{
	char perId[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
	fgets(perId, sizeof(perId), stdin);

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ : %s\n", perId);
	printf("�̸� : %s\n", name);

	return 0;
}