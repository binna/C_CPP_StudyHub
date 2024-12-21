//#include "0_DoublyLinkedList_My.h"
//
//int main(void)
//{
//	Node* list = NULL;
//
//	AppendNode0(&list, 1);
//	AppendNode0(&list, 2);
//	AppendNode0(&list, 3);
//	AppendNode0(&list, 4);
//	AppendNode0(&list, 5);
//	AppendNode0(&list, 6);
//
//	Print0(list);
//
//	InsertNode0(&list, 7, 700);
//	
//	Print0(list);
//
//	InsertNode0(&list, 6, 600);
//
//	Print0(list);
//	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
//
//	InsertNode0(&list, 0, 100);
//
//	Print0(list);
//	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
//
//	ModifyNode0(&list, 0, 0);
//	ModifyNode0(&list, 3, 300);
//	ModifyNode0(&list, 5, 500);
//	ModifyNode0(&list, 7, 7);
//	ModifyNode0(&list, 8, 8);
//	ModifyNode0(&list, 9, 9);
//
//	Print0(list);
//
//	printf("size ��� : %d\n", GetNodeSize0(list));
//	Print0(list);
//
//	DeleteNode0(&list, 7);
//	DeleteNode0(&list, 3);
//	DeleteNode0(&list, 0);
//
//	Print0(list);
//
//	printf("�˻� ��� : %d\n\n", GetNode0(list, 3));
//	printf("�˻� ��� : %d\n\n", GetNode0(list, 7));
//	printf("�˻� ��� : %d\n\n", GetNode0(list, 0));
//
//	printf("size ��� : %d\n", GetNodeSize0(list));
//
//	return 0;
//}


//#include "1_DoublyLinkedList_Book.h"
//
//int main(void)
//{
//	int count = 0;
//
//	Node* List = NULL;
//	Node* NewNode = NULL;
//	Node* Current = NULL;
//
//	// ��� 5�� �߰�
//	for (int i = 0; i < 5; i++)
//	{
//		NewNode = DLL_CreateNode1(i);
//		DLL_AppendNode1(&List, NewNode);
//	}
//
//	// ����Ʈ ���
//	count = DLL_GetNodeCount1(List);
//	for (int i = 0; i < count; i++)
//	{
//		Current = DLL_GetNodeAt1(List, i);
//		printf("List[%d] : %d\n", i, Current->Data);
//	}
//
//	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
//	printf("\nInserting 3000 After [2] ... \n\n");
//
//	Current = DLL_GetNodeAt1(List, 2);
//	NewNode = DLL_CreateNode1(3000);
//	DLL_InsertAfter1(Current, NewNode);
//
//	// ����Ʈ ���
//	count = DLL_GetNodeCount1(List);
//	for (int i = 0; i < count; i++)
//	{
//		Current = DLL_GetNodeAt1(List, i);
//		printf("List[%d] : %d\n", i, Current->Data);
//	}
//
//	// ��� ��带 �޸𸮿��� ����
//	printf("\nDestroying List ... \n");
//
//	count = DLL_GetNodeCount1(List);
//	for (int i = 0; i < count; i++)
//	{
//		Current = DLL_GetNodeAt1(List, 0);
//
//		if (Current != NULL)
//		{
//			DLL_RemoveNode1(&List, Current);
//			DLL_DestroyNode1(Current);
//		}
//	}
//
//	printf(">>> %d\n", DLL_GetNodeCount1(List));
//
//	return 0;
//}


#include "2_DoublyLinkedList_Final.h"

int main(void)
{
	Node* list = NULL;

	DLL_AppendNode2(&list, 1);
	DLL_AppendNode2(&list, 2);
	DLL_AppendNode2(&list, 3);
	DLL_AppendNode2(&list, 4);
	DLL_AppendNode2(&list, 5);
	DLL_AppendNode2(&list, 6);

	DLL_Print2(list);

	DLL_InsertNode2(&list, 7, 700);

	DLL_Print2(list);

	DLL_InsertNode2(&list, 6, 600);

	DLL_Print2(list);

	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	DLL_InsertNode2(&list, 0, 100);

	DLL_Print2(list);
	
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	DLL_ModifyNode2(&list, 0, 0);
	DLL_ModifyNode2(&list, 3, 300);
	DLL_ModifyNode2(&list, 5, 500);
	DLL_ModifyNode2(&list, 7, 7);
	DLL_ModifyNode2(&list, 8, 8);
	DLL_ModifyNode2(&list, 9, 9);

	DLL_Print2(list);

	printf("size ��� : %d\n", DLL_GetNodeSize2(list));
	DLL_Print2(list);

	DLL_RemoveNode2ByLocation(&list, 7);
	DLL_RemoveNode2ByLocation(&list, 3);
	DLL_RemoveNode2ByLocation(&list, 0);

	DLL_Print2(list);

	Node* Data1 = DLL_GetNode2(list, 3);
	Node* Data2 = DLL_GetNode2(list, 7);
	Node* Data3 = DLL_GetNode2(list, 0);
	printf("�˻� ��� : %d\n\n", Data1 == NULL ? -1 : Data1->Data);
	printf("�˻� ��� : %d\n\n", Data2 == NULL ? -1 : Data2->Data);
	printf("�˻� ��� : %d\n\n", Data3 == NULL ? -1 : Data3->Data);

	printf("size ��� : %d\n", DLL_GetNodeSize2(list));

	return 0;
}