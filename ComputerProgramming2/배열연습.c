#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void initArray(int a[][10], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 10; j++)
			a[i][j] = 5 - rand() % 10; // -4에서 5까지의 수를 넣는다
}

void printArray(int a[][10], int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 10; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

// b[i][j]에 a[i][j]의 왼쪽, 오른쪽 양수를 더해 넣는다. 음수는 무시한다
void makeArray(int a[][10], int b[][10], int size)
{
	int i, j;
	int left, right;

	for(i = 0; i < size; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((j - 1) != -1 && a[i][j - 1] >= 0)
				b[i][j] = a[i][j - 1];
			if ((j + 1) != 10 && a[i][j + 1] >= 0)
				b[i][j] += a[i][j + 1];
		}
	}

}
int main(void)
{
	int a[SIZE][10];
	int b[SIZE][10] = {0};
	initArray(a, SIZE);
	makeArray(a, b, SIZE);
	
	printf("배열 A:\n");
	printArray(a, SIZE);

	printf("배열 B:\n");
	printArray(b, SIZE);
}
