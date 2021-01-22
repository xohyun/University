//Project(ƽ�����غ�) 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#define SIZE 3

void display(char b[][3])
{
	int i, j;

	printf("    ");
	for (i = 0; i < SIZE; i++)
		printf("%2d", i);
	printf("\n    ------\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%d  :", i);
		for (j = 0; j < 3; j++)
			printf("%2c", b[i][j]);
		printf("\n");
	}
}
int process(char b[][SIZE], char player)
{
	int row, column;
	static int count = 0;

	printf("Player %c(�� ��):", player);
	scanf("%d %d", &row, & column);

	if (b[row][column] == ' ')
	{
		b[row][column] = player;
		count++;
		display(b);
	}
	return count;
}
int main(void)
{
	char play[SIZE][SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int c = 0;
	char player;

	display(play);
	do
	{
		if (c % 2 == 0)
			player = 'X';
		else
			player = 'O';

		c = process(play, player);
	}while (c < 9);

	printf("\n���� �������ϴ�.\n");
}