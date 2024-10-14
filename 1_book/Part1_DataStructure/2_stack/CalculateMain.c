//#include "0_Calculate_My.h"
//
//// �̷��� ���ذ� �ȵǼ� �����ߴ� ��α�
//// https://www.crocus.co.kr/1703
//
//// Key Point
//// 1. �ǿ����ڰ� ������ �ٷ� ����Ѵ�
//// 2. �����ڰ� ������ �켱������ ���ų� ���� �͵��� ���� ����ϰ� �ڽ��� ���ÿ� ��´�
//// 3. ���� ��ȣ�� ������ ���ÿ� ��´�
//// 4. �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���� ������ ����Ѵ�
//
//// �� �ڵ忡 �Ѱ�
//// 1. ���ڰ� 0 ~ 9������ ������
//
//int main(void)
//{
//	ConvertPostfix0("3+(5+3/2)+7");
//	ConvertPostfix0("3+(5+3*2)+7");
//	ConvertPostfix0("3+7+8");
//	ConvertPostfix0("3+7+9-8");
//	ConvertPostfix0("3+7/9-8");
//	ConvertPostfix0("3+4+7/9-8");
//	ConvertPostfix0("3+6/7");
//	printf("��� : %s\n", ConvertPostfix0("3+(5+3*2)+7"));
//
//	printf("\n\n");
//
//	double resultNum = Calculate0("132*-");
//	printf("result : %lf\n", resultNum);
//
//	resultNum = Calculate0("3532*++7+");
//	printf("result : %lf\n", resultNum);
//
//	resultNum = Calculate0(ConvertPostfix0("3+(5+3*2)+7"));
//	printf("result : %lf\n", resultNum);
//
//	return 0;
//}

//#include "1_Calculate_book.h"
//
//int main(void)
//{
//	char InfixExpression[100];
//	char PostfixExpression[100];
//
//	double result = 0.0;
//
//	memset(InfixExpression, 0, sizeof(InfixExpression));
//	memset(PostfixExpression, 0, sizeof(PostfixExpression));
//
//	printf("Enter Infix Expression: ");
//	scanf_s("%s", InfixExpression, sizeof(InfixExpression));
//	
//
//	GetPostfix(InfixExpression, PostfixExpression);
//
//	printf("Infix: %s\nPostfix: %s\n\n", InfixExpression, PostfixExpression);
//
//	result = Calculate(PostfixExpression);
//
//	printf("Calculate Result : %lf\n", result);
//
//	return 0;
//}

#include "2_Calculate_Final.h"

int main(void)
{
	char InfixExpression[100] = "1+3.334/(4.38*(110-7729))";
	char PostfixExpression[100];

	double result = 0.0;

	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	GetPostfix2(InfixExpression, PostfixExpression);

	printf("Infix: %s\nPostfix: %s\n\n", InfixExpression, PostfixExpression);

	result = Calculate2(InfixExpression, 0);

	printf("Calculate Result : %lf\n", result);
	printf("\n\n");

	result = Calculate2(PostfixExpression, 1);

	printf("Calculate Result : %lf\n", result);

	return 0;
}