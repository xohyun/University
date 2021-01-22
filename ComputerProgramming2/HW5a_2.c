//HW5a_2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
void printArray(int a[][4], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}
void rotation(int a[][4], int b[][4], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 4; j++)
			b[j][3 - i] = a[i][j];
}
void copyArray(int a[][4], int b[][4], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 4; j++)
			b[i][j] = a[i][j];
}
int main(void)
{
	int A[4][4], B[4][4];
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			A[i][j] = 4 * i + (j + 1);

	for (i = 0; i < 5; i++)
	{
		printArray(A, 4);	//A�� ���.
		printf("\n");
		rotation(A, B, 4);	//90�� ȸ���ؼ� B�� ����.
		copyArray(B, A, 4);	//B�� A�� ����.
	}
}