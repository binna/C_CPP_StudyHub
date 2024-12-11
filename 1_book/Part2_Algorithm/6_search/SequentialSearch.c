#include "SingleLinkedList.h"

#include <stdio.h>
#include <string.h>

#pragma region ���� Ž��
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
#pragma endregion

#pragma region �ڱ� ���� ���� Ž��
// ���� �̵���
// ��� �׸��� �� �� Ž���ϰ� ����, �� �׸��� ������ ������ ���� �տ� ��ġ��Ű�� ���
Node* SLL_MoveToFront(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* Previos = NULL;
	Node* Match = NULL;

	while (Current != NULL)
	{
		// ã���� �ϴ� ���� �ش� ��尡 ���� ������
		// ����� �ּҸ� Match�� �����Ѵ�
		if (Current->Data == Target)
		{
			Match = Current;

			if (Previos != NULL)
			{
				// �ڽ��� �� ���� ���� ��带 ����
				Previos->NextNode = Current->NextNode;

				// �ڽ��� ����Ʈ�� ���� ������ �ű��
				Current->NextNode = (*Head);
				(*Head) = Current;
			}
			break;
		}
		Previos = Current;
		Current = Current->NextNode;
	}
	
	return Match;
}

// ���� �̵��� - �迭 ����
void SLL_MoveToFrontArray(int DataSet[], int Length, int Target)
{
	for (int i = 0; i < Length; i++)
	{
		if (DataSet[i] == Target)
		{
			memmove(&DataSet[1], &DataSet[0], sizeof(int) * i);
			DataSet[0] = Target;
			break;
		}
	}
}
#pragma endregion

int main(void)
{
	int DataSet[] = { 5,6,1,2,3,4 };
	int size = sizeof DataSet / sizeof DataSet[0];

	for (int i = 0; i < size; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");

	SLL_MoveToFrontArray(DataSet, size, 3);
	SLL_MoveToFrontArray(DataSet, size, 1);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", DataSet[i]);
	}

	return 0;
}