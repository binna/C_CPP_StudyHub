#include "1_CircularLinkedList_Book.h"

// ��� ����
Node* CDLL_CreateNode1(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �߰�
void CDLL_AppendNode1(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if (*Head == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		
		Node* Tail = (*Head)->PrevNode;		// ���ϰ� ��� ���̿� NewNode�� ����
		
		Tail->NextNode->PrevNode = NewNode;	// Tail->NextNode->PrevNode�� �ᱹ Head�� Prev
											// Head�� Prev�� ���� �߰��ϴ� ��忩�� ��
		Tail->NextNode = NewNode;			// ���� �ڿ� ���ο� ��� ����
											// ���ο� ��尡 ���� ����

		NewNode->NextNode = *Head;
		NewNode->PrevNode = Tail;			// ������ ������ ���ο� ������ PrevNode�� ����Ŵ
	}
}

// ��� ����
void CDLL_InsertAfter1(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}

// ��� �Ҹ�
void CDLL_DestroyNode1(Node* Node)
{
	free(Node);
}

// ��� ����
// å �����δ� �Ʒ��� ���� �ڵ尡 ¥�� ������ ��ü ������ ���� �߻���
void CDLL_RemoveNode1(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;	// ������ Prev(=���� ����)�� Next(=��� ����) = ����� ���� ���
		(*Head)->NextNode->PrevNode = Remove->PrevNode;	// ������ Next�� Prev(=���ο� ��忡 ���� ���� ����) = ����� Prev(= ����)

		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// ��� Ž��
Node* CDLL_GetNodeAt1(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� �� ����
int CDLL_GetNodeCount1(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;

		if (Current == Head)
			break;
	}

	return Count;
}

// ���
void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);

	printf("  Current: %d", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->NextNode->Data);
}