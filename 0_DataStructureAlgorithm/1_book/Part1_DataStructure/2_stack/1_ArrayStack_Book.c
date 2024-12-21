#include "1_ArrayStack_Book.h"

// ������? �ּҸ� ���� ���� �����ϴ� ��

void AS_CreateStack1(ArrayStack** Stack, int Capacity)
{
	// ������ ��������ҿ� ����
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice : No Stack Info\n");
		return;
	}

	// �Էµ� Capacity��ŭ�� ��带 ��������ҿ� ����
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	if ((*Stack)->Nodes == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	// Capacity �� Top �ʱ�ȭ
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack1(ArrayStack* Stack)
{
	// ��带 ��������ҿ��� ����
	free(Stack->Nodes);

	// ������ ��������ҿ��� ����
	free(Stack);
}

void AS_Push1(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top += 1;
}

ElementType AS_Pop1(ArrayStack* Stack)
{
	int Position = --(Stack->Top);
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top1(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;
	return Stack->Nodes[Position].Data;
}

int AS_GetSize1(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty1(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}

int AS_IsFull1(ArrayStack* Stack)
{
	return (Stack->Top == Stack->Capacity);
}