#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
};
int main(void)
{
	struct student aStudent;

	printf("Enter student name: ");
	scanf("%s", aStudent.name);

	printf("Enter midterm and final score: ");
	scanf("%d %d", &aStudent.midterm, &aStudent.final);

	printf("\n이름\t중간\t학기말\n");
	printf("%s\t%d\t%d\n", aStudent.name, aStudent.midterm, aStudent.final);
}