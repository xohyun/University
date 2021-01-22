//LAB1_1 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int main(void)
{
	int num[5];
	int i, total = 0;

	for (i = 0; i < 5; i++)
	{
		printf("Enter %dth number : ", i + 1);
		scanf("%d", &num[i]);

		total += num[i];
	}

	printf("-------------------------\n");
	printf("총합은 %d\n", total);
	printf("평균은 %d\n", total / 5);
	printf("-------------------------\n");

	for (i = 0; i < 5; i++)
		printf("array[%d] : %d\n", i, num[i]);

	return 0;
}