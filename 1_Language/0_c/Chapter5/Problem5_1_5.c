#include <stdio.h>

int main(void)
{
	char ch;
	printf("�ƽ�Ű ���� �Է�: ");
	scanf_s("%c", &ch, sizeof(char));
	printf("�ƽ�Ű �ڵ� ��: %d\n", ch);
	return 0;
}