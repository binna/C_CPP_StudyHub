#include "1_Calculate_book.h"

char NUMER[] = { '0','1','2','3','4','5','6','7','8','9','.' };

int IsNumber(char Cipher)
{
	int i = 0;
	int ArryLength = sizeof(NUMER);

	for (int i = 0; i < ArryLength; i++)
	{
		if (Cipher == NUMER[i])
			return 1;
	}

	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++)
	{
		Token[i] = Expression[i];

		if (IsNumber(Expression[i]) == 1)
		{
			*TYPE = OPERAND;

			if (IsNumber(Expression[i+1]) != 1)
				break;
		}
		else
		{
			*TYPE = Expression[i];
			break;
		}
	}

	Token[++i] = '\0';
	return i;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

// ��ū : �ؽ�Ʈ �м������� ��ū�� �ּ� ������ ��ȣ �Ǵ� �ܾ �ǹ�
void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;

	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	LLS_CreatStack(&Stack);

	while (Position < Length)			// ���� ǥ������ �� ���� ������
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type);

		if (Type == OPERAND)			// ��ū�� �ǿ����ڶ�� ���� ǥ��Ŀ� ���
		{
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");
		}
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(Stack))	// ��ū�� ������ ��ȣ��� ���� ��ȣ�� ��Ÿ�� ������ ������ ��带 ����
			{
				Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] == LEFT_PARENTHESIS)
				{
					LLS_DestroyNode(Popped);
					break;
				}
				else
				{
					strcat(PostfixExpression, Popped->Data);
					LLS_DestroyNode(Popped);
				}
			}
		}
		else							// ��ū�� �������� ���
		{
			// 1. ������ ������� ����
			// 2. ���� �ȿ� �ִ� �����ڿ� ���� Ÿ���� �������� �켱���� ��
			while (!LLS_IsEmpty(Stack) && 
				!IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
			{
				Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] != LEFT_PARENTHESIS)
					strcat(PostfixExpression, Popped->Data);

				LLS_DestroyNode(Popped);
			}

			LLS_Push(Stack, LLS_CreateNode(Token));
		}
	}

	// ���� ǥ������ �� �о����� 
	// ���ÿ� ������ �ִ� ��� �����ڸ� ���� ǥ��Ŀ� ���
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);

		if (Popped->Data[0] != LEFT_PARENTHESIS)
			strcat(PostfixExpression, Popped->Data);

		LLS_DestroyNode(Popped);
	}

	LLS_DestroyStack(Stack);
}

double Calculate(char* PostfixExpression)
{
	LinkedListStack* Stack;
	Node* ResultNode;

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreatStack(&Stack);

	while (Read < Length) 
	{
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
		{
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode);
		}
		else
		{
			char ResultString[32];
			double Operator1, Operator2, TempResult = 0.0;
			Node* OperatorNode;

			OperatorNode = LLS_Pop(Stack);
			Operator2 = atof(OperatorNode->Data);	// double atof(const char* _String); 
													// ���ڿ�(char*)�� �Ǽ�(double)�� ��ȯ�ϱ� ���� ���
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack);
			Operator1 = atof(OperatorNode->Data); 
			LLS_DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS:
				TempResult = Operator1 + Operator2;
				break;
			case MINUS:
				TempResult = Operator1 - Operator2;
				break;
			case MULTIPLY:
				TempResult = Operator1 * Operator2;
				break;
			case DIVIDE:
				TempResult = Operator1 / Operator2;
				break;
			}

			// errno_t _gcvt_s(char *buffer, size_t sizeInBytes, double value, int digits);
			// �ε� �Ҽ��� ���� ���ڿ��� ��ȯ
			// buffer ��ȯ ����� ������ ����, sizeInBytes ������ ũ��, value ��ȯ�� ��, digits ����� ��ȿ �ڸ���
			_gcvt_s(ResultString, sizeof(ResultString), TempResult, 10);
			LLS_Push(Stack, LLS_CreateNode(ResultString));
		}
	}

	ResultNode = LLS_Pop(Stack);
	Result = atof(ResultNode->Data);

	LLS_DestroyNode(ResultNode);
	LLS_DestroyStack(Stack);

	return Result;

}

int GetPriority(char Operator, int InStack)
{
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack)
			Priority = 3;
		else
			Priority = 0;
		break;

	case MULTIPLY:
	case DIVIDE:
		Priority = 1;
		break;
	case PLUS:
	case MINUS:
		Priority = 2;
		break;
	}

	return Priority;
}