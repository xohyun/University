//HW11_1 20170988 컴퓨터학과 17학번 한소현
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
	struct student *sp = s;
	int i;
	int mid_average = 0, final_average = 0;
	char grade;

	for (i = 0; i < 3; i++)
	{
		printf("Enter student name: ");
		scanf("%s", sp->name);

		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp->midterm, &sp->final);

		sp->average = (sp->midterm + sp->final) / 2;
		mid_average += sp->midterm;
		final_average += sp->final;
		sp++;
	}
	mid_average /= 3;
	final_average /= 3;
	sp = s;

	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < 3; i++)
	{
		printf("%s\t%d\t%d%\t%d\n", sp->name, sp->midterm, sp->final, sp->average);
		sp++;
	}
	sp = s;

	printf("\n이름\t학점\n");
	for (i = 0; i < 3; i++)
	{
		if (sp->average >= 80)
			grade = 'A';
		else if (sp->average < 80 && sp->average >= 50)
			grade = 'B';
		else
			grade = 'F';
		printf("%s\t%c\n", sp->name, grade);
		sp++;
	}

	printf("\n중간고사의 평균 = %d\n", mid_average);
	printf("학기말고사의 평균 = %d\n", final_average);
}