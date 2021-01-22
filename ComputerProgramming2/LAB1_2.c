//LAB1_2 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int data[50];
	int num, i, max = -99;

	srand(time(NULL));

	printf("Enter the number of random numbers:(<=50): ");
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		data[i] = rand() % 100;
		if (max < data[i])
			max = data[i];
	}

	printf("최대값은 %d\n", max);
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