#include "RedBlackTree.h"

// => ������ ����Ʈ���� ���� ���� ��

// Nil ���
// RB Ʈ������ leaf ���� Nil ���
// �ƹ� �����͸� ���� ������ ������ ���� �������� ���� ����̴�
extern RBTNode* Nil;

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Right = NewData;
	NewNode->Color = BLACK;
	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return NULL;

	if (Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);

	if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);

	return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return Nil;

	if (Tree->Left == Nil)
		return Tree;

	return RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
	if ((*Tree) == NULL)
		(*Tree) = NewNode;

	if ((*Tree)->Data < NewNode->Data)
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNode(&(*Tree)->Right, NewNode);
		}
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
		}
	}
}

RBTNode* BST_RemoveNode(RBTNode** Root, ElementType Data)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL)
		return NULL;

	if (Target->Left == Nil || Target->Right == Nil)
	{
		Removed = Target;
	}
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Le)

	return nullptr;
}

void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
		RBT_DestroyTree(Tree->Right);

	if (Tree->Left != Nil)
		RBT_DestroyTree(Tree->Left);

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

// ���� �� Ʈ���� ��Ģ ===============================================
// 1. ��� ���� ������ �ƴϸ� �������̴�
// 2. ��Ʈ ���� �������̴�
// 3. �� ���� �������̴�
// 4. ���� ����� �ڽĵ��� ��� �������̴�
//    ������ ������ ����� �ڽ��� �������� �ʿ�� ����
//    ��, ���� ���� ���������� ������ �� ����
// 5. ��Ʈ ��忡�� ��� �� ��� ���̿� �ִ� ������ ����� ���� �����ϴ�
// ===================================================================

// ���� ��Ģ ==========================================================
// ** �����ϴ� �� ���� ������ **
// 1. ���̵� �������� ���
//    �θ� ���� ���� ��带 ���������� ĥ�ϰ� 
//    �Ҿƹ��� ��带 ���������� ĥ�ϸ� ��
//    �� 4�� ��Ģ�� �����ϰ� �ִ��� üũ
// 2. ������ �������̸鼭 ���� ������ ��尡 �θ� ����� ������ �ڽ��� ���
//    �θ� ��带 �������� ȸ������ 
//    �� ��Ȳ�� �� ��° ����� ������ �ٲ۴�
// 3. ������ �������̸鼭 ���� ������ ��尡 �θ� ����� ���� �ڽ��� ���
//    �θ� ��带 ������, �Ҿƹ��� ��带 ���������� ĥ�� ����
//    �Ҿƹ��� ��带 ���������� ȸ��
//    �� ����°�� ��츦 ó���ϰ� �� �������� 4�� ��Ģ�� ���ݵ��� �ʴ´�
// ===================================================================
void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
	// 4�� ��Ģ�� �����ϰ� �ִ� ���ȿ��� ��� �ݺ��Ѵ�
	while (X != (*Root) && X->Parent->Color == RED)
	{
		// �θ� ��尡 �Ҿƹ��� ����� ���� �ڽ��� ���
		if (X->Parent == X->Parent->Parent->Left)
		{
			// ������ ������
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->Color == RED)		// ������ �������� ���
			{
				// ���� 1�� ��Ģ
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent = RED;

				// 4�� ��Ģ�� �����ϰ� �ִ��� üũ
				X = X->Parent->Parent;
			}
			else							// ������ �������� ���
			{
				if (X == X->Parent->Right)	// X�� ������ �ڽ��� ��
				{
					// ���� 2�� ��Ģ
					X = X->Parent;
					RBT_RotateLeft(Root, X);
				}

				// 3�� ��Ģ ó��
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateRight(Root, X);
			}
		}

		// �θ� ��尡 �Ҿƹ��� ����� ������ �ڽ��� ���
		else
		{
			// ������ ����
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->Color == RED)
			{
				// ���� 1�� ��Ģ
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent = RED;

				// 4�� ��Ģ�� �����ϰ� �ִ��� üũ
				X = X->Parent->Parent;
			}
			else							// ������ �������� ���
			{
				if (X == X->Parent->Left)	// X�� ���� �ڽ��� ��,
				{
					// ���� 2�� ��Ģ
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}

				// ���� 3�� ��Ģ
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateLeft(Root, X);
			}
		}
	}

	// ��Ʈ ���� �ݵ�� �������̾�� �Ѵ�
	(*Root)->Color = BLACK;
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
	{
		LeftChild->Right->Parent = Parent;
	}

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = LeftChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = LeftChild;
		}
		else
		{
			Parent->Parent->Right = LeftChild;
		}

		LeftChild->Right = Parent;
		Parent->Parent = LeftChild;
	}
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
	{
		RightChild->Left->Parent = Parent;
	}

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = RightChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = RightChild;
		}
		else
		{
			Parent->Parent->Right = RightChild;
		}

		RightChild->Left = Parent;
		Parent->Parent = RightChild;
	}
}

// ���� ��Ģ ==========================================================
// - ������ ��尡 �������� ���, � ��ó���� �� �ʿ䰡 ����
// - ������ ��尡 �������� ���, 4���� 5���� ��Ģ�� �������� ������ ��ġ�� �ʿ��ϴ�
//                              �̶� ��ġ�ϴ� ���� ���� ��� ó�� -> 5�� ��Ģ���� 1�� ��Ģ�� �ذ��ϴ� ���� ���� ������
// 1. ������ �������� ���
//    ������ ������, �θ� ���������� ĥ�ϰ�
//    ������� ��尡 ���� �ڽ��� ���� ��ȸ���� ����
// 2. ������ �������̰� ������ ���� �ڽ��� ��� �������� ���
//    ���� ��常 ���������� ĥ�� ����,
//    ������� ��尡 ���� �ִ� �� ���� ������ �� �ϳ��� �θ� ��忡�� �ѱ�
// 3. ������ �������̰� ���� �ڽ��� ������, ������ �ڽ��� �������� ���
//    ���� ��带 ���������� ĥ�ϰ�
//    ���� �ڽ��� ���������� ĥ�� ����,
//    ���� ��带 �������� ��ȸ���� ����
// 4. ������ �������̰� ������ �ڽ��� �������� ���
//    ������� ����� �θ� ��尡 ���� �ִ� ���� ���� ��忡 ĥ�Ѵ�
//    �θ� ���� ���� ����� ������ �ڽ� ��带 ���������� ĥ�ϰ� �θ� ��带 �������� ��ȸ��
// ===================================================================
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;

	// ��Ʈ ����̰ų� ������ ������� �������� �Ѿ�� ���� ����
	while (Successor->Parent != NULL && Successor->Color == BLACK)
	{
		// Successor�� �θ��� ���� ����� ��,
		if (Successor == Successor->Parent->Left)
		{
			Sibling = Successor->Parent->Right;

			// 1. ������ �������� ���
			if (Sibling->Color == RED)
			{
				// ������ ������, �θ� ���������� ĥ�Ѵ�
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;

				// ������� ��尡 ���� �ڽ��϶��� ��ȸ���� ����
				RBT_RotateLeft(Root, Successor->Parent);
			}

			// 2. 3. 4. ������ �������̰�
			else
			{
				// 2. ������ ���� �ڽ��� �������� ��
				if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
				{
					// ���� ��常 ���������� ĥ�� ����
					Sibling->Color = RED;
					// ������� ��尡 ���� �ִ� �� ���� ������ �� �ϳ��� �θ� ��忡�� �ѱ�
					Successor = Successor->Parent;
				}
				else
				{
					// 3. ������ ���� �ڽ��� �������� ��
					if (Sibling->Left->Color == RED)
					{
						// ���� ��带 ���������� ĥ�ϰ�
						// ���� �ڽ��� ���������� ĥ�� ����,
						Sibling->Left->Color = BLACK;
						Sibling->Color = RED;

						// ���� ��带 �������� ��ȸ���� ����
						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					// 4. ������ �ڽ��� �������� ���
					// ������� ����� �θ� ��尡 ���� �ִ� ���� ���� ��忡 ĥ�Ѵ�
					Sibling->Color = Successor->Parent->Color;
					
					// �θ� ���� ���� ����� ������ �ڽ� ��带 ���������� ĥ�ϰ� 
					Successor->Parent->Color = BLACK;
					Sibling->Right->Color = BLACK;

					// �θ� ��带 �������� ��ȸ��
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}

		// Successor�� �θ��� ������ ����� �� -> ���ʰ� �ݴ��
		else
		{
			Sibling = Successor->Parent->Left;

			// 1. ������ �������� ���
			if (Sibling->Color == RED)
			{
				// ������ ������, �θ� ���������� ĥ�Ѵ�
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;

				// ������� ��尡 ���� �ڽ��϶��� ��ȸ���� ����
				RBT_RotateRight(Root, Successor->Parent);
			}

			// 2. 3. 4. ������ �������̰�
			else
			{
				// 2. ������ ���� �ڽ��� �������� ��
				if (Sibling->Right->Color == BLACK && Sibling->Left->Color == BLACK)
				{
					// ���� ��常 ���������� ĥ�� ����
					Sibling->Color = RED;
					// ������� ��尡 ���� �ִ� �� ���� ������ �� �ϳ��� �θ� ��忡�� �ѱ�
					Successor = Successor->Parent;
				}
				else
				{
					// 3. ������ ���� �ڽ��� �������� ��
					if (Sibling->Right == RED)
					{
						// ���� ��带 ���������� ĥ�ϰ�
						// ���� �ڽ��� ���������� ĥ�� ����,
						Sibling->Right->Color = BLACK;
						Sibling->Color = RED;

						// ���� ��带 �������� ��ȸ���� ����
						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					// 4. ������ �ڽ��� �������� ���
					// ������� ����� �θ� ��尡 ���� �ִ� ���� ���� ��忡 ĥ�Ѵ�
					Sibling->Color = Successor->Parent->Color;
					

					// �θ� ���� ���� ����� ������ �ڽ� ��带 ���������� ĥ�ϰ� 
					Successor->Parent->Color = BLACK;
					Sibling->Left->Color = BLACK;

					// �θ� ��带 �������� ��ȸ��
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}

	Successor->Color = BLACK;
} 