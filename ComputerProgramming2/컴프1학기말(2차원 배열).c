#include <stdio.h>
int main(void)
{
	// 1 �� 1 ȣ���� 2 ���� �迭�� �����Ѵ�
	int bldg[5][4] = {{2, 3, 4, 0}, {3, 3, 3, 0},{4, 5, 6, 0}, {2, 2, 2, 0}, {1, 1, 1, 0}};
	int i, j;
	// ���� �׸����� ȸ�� �κп� �� ���� ���� ���ο��� �־��

	for (i = 0; i < 5; i++)
		for (j = 0; j < 3; j++)
			bldg[i][3] += bldg[i][j];

	for (i = 0; i < 5; i++)
	{
		printf("%d�� : " , i + 1);
		for (j = 0; j < 4; j++)
			printf("%5d", bldg[i][j]);
		printf("\n");
	}
}