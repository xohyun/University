//Challenge5_1 20170988 컴퓨터학과 17학번 한소현
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

		printf("몇번째 좌석을 예약하시겠습니까? (열 행)의 형태로 입력:");
		scanf("%d %d", &row, &column);

		processReservation(seats, SIZE, row, column);

		while (getchar() != '\n'); // 버퍼 비움
	}
}
char askReservation()
{
	char choice;

	printf("좌석을 예약하시겠습니까?(y/n) ");
	scanf("%c", &choice);

	return choice;
}
void processReservation(int s[][SIZE], int size, int row, int column)
{
	if (s[row - 1][column - 1] == 0)
	{
		s[row - 1][column - 1] = 1;
		printf("예약되었습니다.\n");
		printSeats(s, 3);
	}
	else
		printf("이미 예약된 자리입니다.\n");
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