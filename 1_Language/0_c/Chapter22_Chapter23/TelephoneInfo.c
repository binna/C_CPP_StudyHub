#include <stdio.h>
#include <string.h>

struct person
{
	char name[20];
	char phonenum[20];
	int age;
};
int main(void)
{
	struct person man1, man2;
	strcpy_s(man1.name, sizeof(man1.name), "�ȼ���");
	strcpy_s(man1.phonenum, sizeof(man1.phonenum), "010-1111-1111");
	man1.age = 23;

	printf("�̸� �Է�: "); scanf_s("%s", man2.name, sizeof(man2.name));
	printf("��ȣ �Է�: "); scanf_s("%s", man2.phonenum, sizeof(man2.phonenum));
	printf("���� �Է�: "); scanf_s("%d", &man2.age);

	printf("�̸� : %s\n", man1.name);
	printf("��ȣ : %s\n", man1.phonenum);
	printf("���� : %d\n", man1.age);

	printf("�̸� : %s\n", man2.name);
	printf("��ȣ : %s\n", man2.phonenum);
	printf("���� : %d\n", man2.age);

	return 0;
}