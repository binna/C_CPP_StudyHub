#include <stdio.h>

typedef struct dbshost
{
	unsigned short upper;
	unsigned short lower;
} DBShort;

typedef union rdbuf
{
	int iBuf;
	char bBuf[4];
	DBShort sBuf;
} RDBuf;

int main(void)
{
	RDBuf buf;
	printf("���� �Է� : ");
	scanf_s("%d", &buf.iBuf);

	printf("���� 2����Ʈ : %u \n", buf.sBuf.upper);
	printf("���� 2����Ʈ : %u \n\n", buf.sBuf.lower);

	printf("���� 1����Ʈ �ƽ�Ű �ڵ� : %c \n", buf.bBuf[0]);
	printf("���� 1����Ʈ �ƽ�Ű �ڵ� : %c \n", buf.bBuf[1]);
	printf("���� 1����Ʈ �ƽ�Ű �ڵ� : %c \n", buf.bBuf[2]);
	printf("���� 1����Ʈ �ƽ�Ű �ڵ� : %c \n", buf.bBuf[3]);

	return 0;
}