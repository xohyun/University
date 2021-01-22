//20170988 컴퓨터학과 한소현
#include <stdio.h>
void printArray(int a[][4], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int A[4][4], B[4][4];
	int i, j;

	// A에 값을 넣어 출력
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			A[i][j] = 4 * i + (j + 1);
	printArray(A, 4);
	printf("\n");

	// A를 이용하여 B에 값을 넣어 B를 출력
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			B[j][3 - i] = A[i][j];
	printArray(B, 4);
}