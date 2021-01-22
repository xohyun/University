//Challenge5_1 20170988 ��ǻ���а� 17�й� �Ѽ���
#define SIZE 10
#include <stdio.h>

char askReservation();
void printSeats(int s[][SIZE], int size);
void processReservation(int s[][SIZE], int size, int row, int column);

int main(void)
{
	int row, column;
	int seats[3][SIZE] = {0};

	while (askReservation() == 'y')
	{
		printSeats(seats, 3);

		printf("���° �¼��� �����Ͻðڽ��ϱ�? (�� ��)�� ���·� �Է�:");
		scanf("%d %d", &row, &column);

		processReservation(seats, SIZE, row, column);

		while (getchar() != '\n'); // ���� ���
	}
}
char askReservation()
{
	char choice;

	printf("�¼��� �����Ͻðڽ��ϱ�?(y/n) ");
	scanf("%c", &choice);

	return choice;
}
void processReservation(int s[][SIZE], int size, int row, int column)
{
	if (s[row - 1][column - 1] == 0)
	{
		s[row - 1][column - 1] = 1;
		printf("����Ǿ����ϴ�.\n");
		printSeats(s, 3);
	}
	else
		printf("�̹� ����� �ڸ��Դϴ�.\n");
}
void printSeats(int s[][SIZE], int size)
{
	int i, j;

	printf("-----------------------------------------\n\t");
	for (i = 0; i < SIZE; i++)
		printf("%3d", i + 1);
	printf("\n-----------------------------------------\n");

	for (i = 0; i < size; i++)
	{
		printf("%d	", i + 1);
		for (j = 0; j < SIZE; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
	printf("\n");
}