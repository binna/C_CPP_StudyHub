#include <stdio.h>

// ������ ���� ����
// ���� ������ �̸� ���ĵǾ� �־ ��� ������ ���� �񱳸� �����ϴ� �̷��ϱ� �������� �˰���!
// => ���ĵǾ� �ִ� ��쿡�� ������ ����ϰ� ������������ ���� �Ϸ�

void Bubble(int* data, int lengh)
{
	int i, j, temp, isSort;
	for (i = 0; i < lengh - 1; i++)
	{
		isSort = 1;

		for (j = 0; j < lengh - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				isSort = 0;
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}

		if (isSort == 1)
		{
			printf("in %d\n", i);
			break;
		}
	}
}

int main(void)
{
	int data1[] = { 5,1,6,4,2,3 };
	int data2[] = { 1,2,3,4,6,5 };
	int size = sizeof(data1) / sizeof(int);

	Bubble(data2, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", data2[i]);
	}
}