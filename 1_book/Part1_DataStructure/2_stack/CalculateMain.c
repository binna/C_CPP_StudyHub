#include "0_Calculate_My.h"

// �̷��� ���ذ� �ȵǼ� �����ߴ� ��α�
// https://www.crocus.co.kr/1703

// Key Point
// 1. �ǿ����ڰ� ������ �ٷ� ����Ѵ�
// 2. �����ڰ� ������ �켱������ ���ų� ���� �͵��� ���� ����ϰ� �ڽ��� ���ÿ� ��´�
// 3. ���� ��ȣ�� ������ ���ÿ� ��´�
// 4. �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���� ������ ����Ѵ�

// �� �ڵ忡 �Ѱ�
// 1. ���ڰ� 0 ~ 9������ ������

int main(void)
{
	//ConvertPostfix0("3+(5+3/2)+7");
	ConvertPostfix0("3+7+8");
	ConvertPostfix0("3+7+9-8");
	ConvertPostfix0("3+7/9-8");
	ConvertPostfix0("3+4+7/9-8");
	printf("��� : %s\n", ConvertPostfix0("3+(5+3*2)+7"));

	printf("\n\n");

	double resultNum = Calculate0("132*-");
	printf("result : %lf\n", resultNum);

	resultNum = Calculate0("3532*++7+");
	printf("result : %lf\n", resultNum);

	return 0;
}