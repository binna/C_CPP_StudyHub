#include "SingleLinkedList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

#pragma region �ڱ� ���� ���� Ž�� - ���� ����ϴ� �׸��� ������ ������ ���ʿ� ��ġ

#pragma region ���� �̵���
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

#pragma region ������
// ������
// Ž���� �׸��� �ٷ� ���� �׸�� ��ȯ�Ѵ� -> ���� ������ ���� �����͸� ������ ������ ���ʿ� ������
Node* SLL_Transpose(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* PPrevious = NULL;		// ��������� �������
	Node* Previous = NULL;		// �������
	Node* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;
			if (Previous != NULL)
			{
				if (PPrevious != NULL)
					PPrevious->NextNode = Current;
				else
					(*Head) = Current;

				Previous->NextNode = Current->NextNode;
				Current->NextNode = Previous;
			}
			break;
		}

		PPrevious = Previous;
		Previous = Current;
		Current = Current->NextNode;
	}

	return Match;
}

// ������ - �迭 ����
void SLL_TransposeArray(int DataSet[], int Length, int Target)
{
	for (int i = 0; i < Length; i++)
	{
		if (DataSet[i] == Target)
		{
			if (i != 0)
			{
				int Temp = DataSet[i];
				DataSet[i] = DataSet[i - 1];
				DataSet[i - 1] = Temp;
			}
			break;
		}
	}
}
#pragma endregion

// �����
// ������ ���� ���� �� ��ҵ��� Ž���� Ƚ���� ������ ������ �����صΰ�,
// Ž���� Ƚ���� ���� ������ ������ ������ �籸���ϴ� ������ �˰���

// 1
// ���� �ڿ� �ִ� �����Ͱ� ���� ���� ������ �޴���,
// �������� ������ ũ�� ���� ������ �� �� �ִٴ� ���� ���� ���� �� ����
// ��? �ܰ������� �̵��ϴϱ�
FCMNode1* SLL_FrequencyCountMethod1(FCMNode1** Head, int Target)
{
	FCMNode1* Current = (*Head);
	FCMNode1* PPrevious = NULL;
	FCMNode1* Previous = NULL;
	FCMNode1* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;

			// ��� ������ �߽߰� ī��Ʈ ����
			Current->Cnt += 1;

			// ���ġ �ʿ� ���� Ȯ��
			if (Previous != NULL && Previous->Cnt < Current->Cnt)
			{
				if (PPrevious != NULL)
					PPrevious->NextNode = Current;
				else
					(*Head) = Current;

				// ���� ����Ʈ ��� ���ġ
				Previous->NextNode = Current->NextNode;
				Current->NextNode = Previous;
			}
			break;
		}

		PPrevious = Previous;
		Previous = Current;
		Current = Current->NextNode;
	}
	return Match;
}

// 2
// ���õ� �����Ͱ� ��� �ùٸ� ��ġ�� �̵��ϵ��� �����Ͽ� ����
FCMNode2* SLL_FrequencyCountMethod2(FCMNode2** Head, int Target)
{
	FCMNode2* Current = (*Head);
	FCMNode2* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;

			// ��� ������ �߽߰� ī��Ʈ ����
			Current->Cnt += 1;

			// �˻��� ������ ����, �켱������ ���� ���� �ִ��� Ž��
			FCMNode2* Previous = Current->PrevNode;
			while (Previous != NULL && Previous->Cnt < Current->Cnt)
			{
				Previous = Previous->PrevNode;
			}

			// ���� ���, ���ġ �ʿ� ����
			if (Previous == Current->PrevNode)
				break;

			if (Current->PrevNode != NULL)
				Current->PrevNode->NextNode = Current->NextNode;

			if (Current->NextNode != NULL)
				Current->NextNode->PrevNode = Current->PrevNode;

			if (Previous != NULL)
			{
				if (Previous->NextNode != NULL)
					Previous->NextNode->PrevNode = Current;

				Current->NextNode = Previous->NextNode;
				Previous->NextNode = Current;
				Current->PrevNode = Previous;
			}
			else
			{
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;
				(*Head) = Current;
			}
			break;
		}

		Current = Current->NextNode;
	}
	return Match;
}
#pragma endregion

int main(void)
{
#pragma region �����̵���, ������ �׽�Ʈ
	//int DataSet[] = { 5,6,1,2,3,4 };
	//int size = sizeof DataSet / sizeof DataSet[0];

	//for (int i = 0; i < size; i++)
	//{
	//	printf("%d ", DataSet[i]);
	//}
	//printf("\n");

	////SLL_MoveToFrontArray(DataSet, size, 3);
	////SLL_MoveToFrontArray(DataSet, size, 1);

	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);

	//for (int i = 0; i < size; i++)
	//{
	//	printf("%d ", DataSet[i]);
	//}
#pragma endregion

#pragma region ����� 1 �׽�Ʈ
	//// ������ ���� ////////////////////////////////////////////
	//FCMNode1* Node1 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node1->Data = 1;
	//Node1->Cnt = 0;
	//Node1->NextNode = NULL;

	//FCMNode1* Node2 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node2->Data = 2;
	//Node2->Cnt = 0;
	//Node2->NextNode = NULL;


	//FCMNode1* Node3 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node3->Data = 3;
	//Node3->Cnt = 0;
	//Node3->NextNode = NULL;

	//FCMNode1* Node4 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node4->Data = 4;
	//Node4->Cnt = 0;
	//Node4->NextNode = NULL;

	//Node1->NextNode = Node2;
	//Node2->NextNode = Node3;
	//Node3->NextNode = Node4;

	//FCMNode1* Head = Node1;
	////////////////////////////////////////////////////////////

	//FCMNode1* Current;

	//printf("------------------------\n");
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
	//
	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 1);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 3);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
	//
	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 2);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//if (SLL_FrequencyCountMethod1(&Head, 5) == NULL)
	//{
	//	printf("���(5)�� ã�� �� �����ϴ�.\n");
	//}

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
#pragma endregion

#pragma region ����� 2 �׽�Ʈ
	//// ������ ���� ////////////////////////////////////////////
	FCMNode2* Node1 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node1->Data = 1;
	Node1->Cnt = 0;
	Node1->PrevNode = NULL;
	Node1->NextNode = NULL;

	FCMNode2* Node2 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node2->Data = 2;
	Node2->Cnt = 0;
	Node2->PrevNode = NULL;
	Node2->NextNode = NULL;

	FCMNode2* Node3 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node3->Data = 3;
	Node3->Cnt = 0;
	Node3->PrevNode = NULL;
	Node3->NextNode = NULL;

	FCMNode2* Node4 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node4->Data =4;
	Node4->Cnt = 0;
	Node4->PrevNode = NULL;
	Node4->NextNode = NULL;

	Node2->PrevNode = Node1;
	Node3->PrevNode = Node2;
	Node4->PrevNode = Node3;

	Node1->NextNode = Node2;
	Node2->NextNode = Node3;
	Node3->NextNode = Node4;
	

	FCMNode2* Head = Node1;
	////////////////////////////////////////////////////////////
	FCMNode2* Current;
	printf("------------------------\n");
	Current = Head;
	while (Current != NULL) 
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 2);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 3);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 4);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");
	
#pragma endregion

	return 0;
}