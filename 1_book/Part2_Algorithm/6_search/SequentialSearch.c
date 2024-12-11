#include <stdio.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
}Node;

Node* SLL_SequentialSearch(Node* Head, int Target)
{
	Node* Current = Head;
	Node* Match = NULL;

	while (Current != NULL)
	{
		// ã���� �ϴ� ���� �ش� ��尡 ������ ������
		// ����� �ּҸ� Match�� �����Ѵ�
		if (Current->Data == Target)
		{
			Match = Current;
			break;
		}

		// ���� ��忡 ã�� ���� ������
		// ���� ��带 �����Ѵ�
		Current = Current->NextNode;
	}

	// ã�� ���� ���� �ִ� ����� �ּҸ� ��ȯ�Ѵ�
	return Match;
}