//HW12_1 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	FILE *fp1, *fp2;
	int i, num, total = 0;

	srand(time(NULL));
	fp1 = fopen("random.txt", "w");

	for (i = 0; i < 10; i++)
		fprintf(fp1, "%d\n", rand() % 100);
	fclose(fp1);

	fp1 = fopen("random.txt", "r");
	fp2 = fopen("output.txt", "w");

	fscanf(fp1, "%d", &num);
	while (!feof(fp1))
	{
		total += num;
		fprintf(stdout, "%5d", num);
		fprintf(fp2, "%d\n", num);
		fscanf(fp1, "%d", &num);
	}
	printf("\n합은 %d\n", total);
	fprintf(fp2, "합은 %d\n", total);

	fclose(fp1);
	fclose(fp2);
}