//HW10_1 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
int main(void)
{
	struct student s[3];
	int i;
	int mid_average = 0, final_average = 0;
	char grade;

	for (i = 0; i < 3; i++)
	{
		printf("Enter student name: ");
		scanf("%s", s[i].name);

		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);

		s[i].average = (s[i].midterm + s[i].final) / 2;
		mid_average += s[i].midterm;
		final_average += s[i].final;
	}
	mid_average /= 3;
	final_average /= 3;

	printf("\n�̸�\t�߰�\t�б⸻\t���\n");
	for (i = 0; i < 3; i++)
		printf("%s\t%d\t%d%\t%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);

	printf("\n�̸�\t����\n");
	for (i = 0; i < 3; i++)
	{
		if (s[i].average >= 80)
			grade = 'A';
		else if (s[i].average < 80 && s[i].average >= 50)
			grade = 'B';
		else
			grade = 'F';
		printf("%s\t%c\n", s[i].name, grade);
	}

	printf("\n�߰������ ��� = %d\n", mid_average);
	printf("�б⸻����� ��� = %d\n", final_average);
}