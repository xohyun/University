struct student {
	char name[20];
	int midterm;
	int final;
};

#include <stdio.h>
int main(void)
{
	struct student aStudent;
	struct student *sp = &aStudent;

	printf("Enter student name: ");
	scanf("%s", &(*sp).name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &(*sp).midterm, &(*sp).final);
	
	printf("\n�̸�\t�߰�\t�б⸻\n");	
	printf("%s\t%d\t%d\n", (*sp).name, (*sp).midterm, (*sp).final);	
}	