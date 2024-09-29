#include "0_DoubleLinkedListMy.h"

// ��� �߰�
void AppendNode0(Node** List, int Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	newNode->Data = Data;
	newNode->NextNode = NULL;

	if (*List == NULL)
	{
		*List = newNode;
		return;
	}

	Node* TargetNode = *List;
	while (TargetNode->NextNode != NULL)
	{
		TargetNode = TargetNode->NextNode;
	}

	TargetNode->NextNode = newNode;
	newNode->PrevNode = TargetNode;
}

// ��� �߰� ����
void InsertNode0(Node** List, int Location, int Data)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	newNode->Data = Data;

	if (Location == 0)
	{
		newNode->PrevNode = NULL;
		newNode->NextNode = (*List);

		(*List) = newNode;
		return;
	}

	Node* TargetNode = *List;
	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			if (Location == 0)
			{
				TargetNode->NextNode = newNode;
				newNode->PrevNode = TargetNode;
				newNode->NextNode = NULL;
				return;
			}
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}

	TargetNode->PrevNode->NextNode = newNode;

	newNode->PrevNode = TargetNode->PrevNode;
	newNode->NextNode = TargetNode;

	TargetNode->PrevNode = newNode;
}

// ��� ����
void ModifyNode0(Node** List, int Location, int Data)
{
	if (*List == NULL)
	{
		printf("System Notice : No saved double linked list\n");
		return;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = *List;
	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}
	TargetNode->Data = Data;
}

// ��� ����
void DeleteNode0(Node** List, int Location)
{
	if (*List == NULL)
	{
		printf("System Notice : No deleted double linked list\n");
		return;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = *List;
	if (Location == 0)
	{
		TargetNode->NextNode->PrevNode = NULL;
		*List = TargetNode->NextNode;
		free(TargetNode);
		return;
	}

	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}

	if (TargetNode->NextNode != NULL)
	{
		TargetNode->NextNode->PrevNode = TargetNode->PrevNode;
		TargetNode->PrevNode->NextNode = TargetNode->NextNode;
	}
	else
	{
		TargetNode->PrevNode->NextNode = NULL;
	}

	free(TargetNode);
}

// ��� �˻�
int GetNode0(Node* List, int Location)
{
	if (List == NULL)
	{
		printf("System Notice : a double linked list that does not exist");
		return -1;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return -1;
	}

	Node* TargetNode = List;
	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return -1;
		}
		TargetNode = TargetNode->NextNode;
	}

	return TargetNode->Data;
}

// ��� ����
int GetNodeSize0(Node* List)
{
	int Size = 0;

	Node* TargetNode = List;
	while (TargetNode != NULL)
	{
		TargetNode = TargetNode->NextNode;
		Size += 1;
	}

	return Size;
}

// ��� ��� ���
void Print0(Node* List)
{
	printf("======================\n");
	if (List == NULL)
	{
		printf("System Notice : No saved double linked list\n");
		return;
	}

	Node* TargetNode = List;
	while (TargetNode != NULL)
	{
		printf(">> data : %d\n", TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}
	printf("======================\n");
}