#include "SBT_Tree_my.h"

SBTNode* SBT_CreateNode(ElementType Data)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Data = Data;
	NewNode->Left = NULL;
	NewNode->Rigth = NULL;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// ���� ���� Ʈ�� �Ҹ�
	SBT_DestroyNode(Node->Left);

	// ������ ���� Ʈ�� �Ҹ�
	SBT_DestroyNode(Node->Rigth);

	// ��Ʈ ��� �Ҹ�
	SBT_DestroyNode(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// ��Ʈ ���
	printf("  %c", Node->Data);

	// ���� ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Left);

	// ������ ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Rigth);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// ���� ���� Ʈ�� ���
	SBT_InorderPrintTree(Node->Left);

	// ��Ʈ ���
	printf("   %c", Node->Data);

	// ������ ���� Ʈ�� ���
	SBT_InorderPrintTree(Node->Rigth);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// ���� ���� Ʈ�� ���
	SBT_PostorderPrintTree(Node->Left);

	// ������ ���� Ʈ�� ���
	SBT_PostorderPrintTree(Node->Rigth);

	// ��Ʈ ���
	printf("   %c", Node->Data);
}