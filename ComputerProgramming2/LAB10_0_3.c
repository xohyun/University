struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};

#include <stdio.h>
int main(void)
{
	struct student s[3];
	struct student *sp = s;
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("Enter student name: ");
		scanf("%s", &(*sp).name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &(*sp).midterm, &(*sp).final);
		sp++;
	}
	sp = s;
	printf("\n이름\t중간\t학기말\n");	
	for (i = 0; i < 3; i++)
	{
		printf("%s\t%d\t%d\n", (*sp).name, (*sp).midterm, (*sp).final);	
		sp++;
	}
}	
