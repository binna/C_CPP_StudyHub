#include <stdio.h>
#include <stdlib.h>

#include "Score.h"

typedef int ElementType;

#pragma region ���� Ž��
ElementType BinarySearch1(ElementType DataSet[], int Size, ElementType Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	// Ž�� ������ ũ�Ⱑ 0�� �� ������ ������ �ݺ��Ѵ�
	while (Left <= Right)
	{
		// �߾� ����� ��ġ�� ����Ѵ�
		Mid = (Left + Right) / 2;

		// �߾� ��Ұ� ��� �ִ� ���� ��ǥ ���� ��ġ�ϸ� �ش� ��Ҹ� ��ȯ�ϴ�
		if (Target == DataSet[Mid])
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1; 
		else
			Right = Mid - 1;
	}

	return NULL;
}
#pragma endregion

#pragma region ���� Ž�� ���� - ���� ����
Score* BinarySearch2(Score ScoreList[], int Size, double Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		if (Target == ScoreList[Mid].score)
			return &(ScoreList[Mid]);
		else if (Target > ScoreList[Mid].score)
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	return NULL;
}

// ���� �˰����� 
//  : �� �Լ��� ��ȯ�� ���, ����, 0�� ����� �� ���� ������� ��ġ�� ����
// �� �Լ��� ����� ��ȯ�� ���� ��ȯ�� �̷������
int CompareScore(const void* _elem1, const void* _elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}

int Partition(Score ScoreList[], int Left, int Right)
{
	int First = Left;
	Score Pivot = ScoreList[Left];

	Left += 1;

	while (Left <= Right)
	{
		while (ScoreList[Left].score <= Pivot.score && Left < Right)
			Left += 1;

		while (ScoreList[Right].score > Pivot.score && Left <= Right)
			Right -= 1;

		if (Left >= Right)
			break;

		Score Temp = ScoreList[Left];
		ScoreList[Left] = ScoreList[Right];
		ScoreList[Right] = Temp;
	}

	ScoreList[First] = ScoreList[Right];
	ScoreList[Right] = Pivot;
	return Right;
}

void QuickSort(Score ScoreList[], int Left, int Right)
{
	if (Left < Right)
	{
		int idx = Partition(ScoreList, Left, Right);
		QuickSort(ScoreList, Left, idx - 1);
		QuickSort(ScoreList, idx + 1, Right);
	}
}
#pragma endregion

int main(void)
{
	//int DataSet[] = { 1,7,11,12,14,23,67,139,672,871 };
	//int Length = sizeof DataSet / sizeof DataSet[0];

	//printf("%d\n", BinarySearch1(DataSet, Length, 55));

	//////////////////////////////////////////////////////////

	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	Score target;
	Score* found1 = NULL;
	Score* found2 = NULL;

	// ������ ������������ ����
	//qsort(DataSet, Length, sizeof(Score), CompareScore);
	QuickSort(DataSet, 0, Length - 1);

	target.number = 0;
	target.score = 671.78;

	// 671.78���� ���� �л� ã��
	found1 = BinarySearch2(DataSet, Length, 671.78);
	found2 = bsearch(&target, DataSet, Length, sizeof(Score), CompareScore);

	printf("found1 : %d %f\n", found1->number, found1->score);
	printf("found2 : %d %f\n", found2->number, found2->score);

	return 0;
}