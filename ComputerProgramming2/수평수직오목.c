//����������� 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#define BOARD_SIZE 10

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	int i, j;
	int sum;
	char player = b[r][c]; 

	// ���⿡ ���� ���� ���θ� �Ǵ��ϴ� �ڵ带 ����
	i = c;
	sum = 1;
	while(c + 1 < 10 && b[r][i + 1] == player)
	{
		sum++;
		i++;
	}
	i = c;
	while (i - 1 >= 0 && b[r][i - 1] == player)
	{
		sum++;
		i--;
	}
	if (sum == 5)
		return 1;
	sum = 0;
	
	j = r;
	while (j + 1 < 10 && b[j + 1][c] == player)
	{
		sum++;
		j++;
	}
	j = r;
	while (j - 1 >= 0 && b[j - 1][c] == player)
	{
		sum++;
		j--;
	}
	if (sum == 5)
		return 1;

	return 0;
}

void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;
	printf("     ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n     ---------------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++) 
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

void main()
{
   char board[BOARD_SIZE][BOARD_SIZE];
   char turn = 'X';
   int r, c;
   int i, j;
   int count;
   int lose;
   int win;

   for(i =0; i < BOARD_SIZE ; i++ ) 
	   for(j = 0 ; j < BOARD_SIZE ; j++ ) 
		   board[i][j] = ' ';

   count = 1;
   display(board);
   do 
   {
		printf("Player %c(�� ��):", turn);
        scanf("%d %d", &r, &c);

        if(board[r][c] != ' ') continue; // �̹� ���� ���� �ڸ�

		board[r][c] = turn;
        display(board);

		if (win = winCheck(board, r, c))
			printf("Player %c wins!\n", turn);
		turn = (turn == 'X' ? 'O': 'X');
		count++;
   } while(!win && count <= BOARD_SIZE * BOARD_SIZE);

   if (!win && count == BOARD_SIZE * BOARD_SIZE)
		printf("Nobody win!\n");
}


 
