#include "1_CircularLinkedList_Book.h"

int main(void)
{
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	// ��� 5�� �߰�
	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode1(i);
		CDLL_AppendNode1(&List, NewNode);
	}

	// ����Ʈ ���
	Count = CDLL_GetNodeCount1(List);
	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt1(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = CDLL_GetNodeAt1(List, 2);
	NewNode = CDLL_CreateNode1(3000);
	CDLL_InsertAfter1(Current, NewNode);

	// ����Ʈ ���
	// ��� ���� 2�踸ŭ ������ ���� ȯ������ Ȯ��
	Count = CDLL_GetNodeCount1(List);
	for (int i = 0; i < Count * 2; i++)
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ��� ��带 �޸𸮿��� ����
	printf("\nDestroying List...\n\n");

	Count = CDLL_GetNodeCount1(List);

	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt1(List, 0);

		if (Current != NULL)
		{
			CDLL_RemoveNode1(&List, Current);
			CDLL_DestroyNode1(Current);
		}
	}

	return 0;
}