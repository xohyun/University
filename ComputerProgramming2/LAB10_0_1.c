#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
};
int main(void)
{
	struct student s[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("Enter student name: ");
		scanf("%s", s[i].name);

		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);
	}
	
	printf("\n�̸�\t�߰�\t�б⸻\n");
	for (i = 0; i < 3; i++)
		printf("%s\t%d\t%d\n", s[i].name, s[i].midterm, s[i].final);
}