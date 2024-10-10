#include "1_LinkedListStack_Book.h"

void LLS_CreateStack1(LinkedListStack** Stack)
{
	// ������ ���� ����ҿ� ����
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack1(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty1(Stack))
	{
		Node* Popped = LLS_Pop1(Stack);
		LLS_DestroyNode1(Popped);
	}

	// ������ ���� ����ҿ��� ����
	free(Stack);
}

Node* LLS_CreateNode1(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	strcpy_s(NewNode->Data, strlen(NewData) + 1, NewData);	// �����͸� �����Ѵ�
	NewNode->NextNode = NULL;								// ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ
	return NewNode;											// ����� �ּҸ� ��ȯ
}

void LLS_DestroyNode1(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push1(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		// �ֻ��� ��带 ã�� NewNode�� ����
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}

	// ������ Top �ʵ忡 �� ����� �ּҸ� ���
	Stack->Top = NewNode;
}

Node* LLS_Pop1(LinkedListStack* Stack)
{
	// LLS_Pop1() �Լ��� ��ȯ�� �ֻ��� ���
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// �ֻ��� ��带 ������ Top �ʵ忡 ��� >> ���
		Node* CurrentTop = Stack->List;

		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;

		if (CurrentTop != NULL)
			CurrentTop->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top1(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize1(LinkedListStack* Stack)
{
	unsigned int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count += 1;
	}

	return Count;
}

int LLS_IsEmpty1(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}