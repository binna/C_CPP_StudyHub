#include "SBT_Tree_my.h"

int main(void)
{
	// ��� ����
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	// Ʈ���� ��� �߰�
	A->Left = B;
	B->Left = C;
	B->Rigth = D;

	A->Rigth = E;
	E->Left = F;
	E->Rigth = G;

	// Ʈ�� ���
	printf("Preorder ...\n");
	SBT_PreorderPrintTree(A);
	printf("\n\n");

	printf("Inorder ...\n");
	SBT_InorderPrintTree(A);
	printf("\n\n");

	printf("Piostorder ...\n");
	SBT_PostorderPrintTree(A);
	printf("\n\n");

	return 0;
}