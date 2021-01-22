//HW1_1 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int data[100], count[10] = {0};
	int num, i, j;
	
	//srand(time(NULL));

	printf("Enter the number of random numbers:(<=100): ");
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		data[i] = rand() % 10;
		for (j = 0; j < 10; j++)
			if (data[i] == j)
			{
				count[j]++;
				break;
			}
	}

	for (i = 0; i < 10; i++)
		printf("%d의 개수는 %d\n", i, count[i]);

	printf("------------------------------------------\n");
	printf("발생된 난수는\n");

	for (i = 0; i <  num; i++)
	{
		printf("%5d", data[i]);
		if (i % 5 == 4)
			printf("\n");
	}
	printf("\n");
}