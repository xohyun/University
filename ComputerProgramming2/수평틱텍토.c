//����ƽ���� 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int win_check(int x, int y, int board[][3]) // �¸� üũ
{
	int i, sum = 0;
	
	for (i = 0; i < 3; i++)
		sum += board[x][i];
	if (sum == 3 || sum == -3)
		return 1;
	return 0;
}

void print_board(int board[][3]) 
{
	int i, j, c;

	printf("    0 1 2\n   -------\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d : ", i);
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] == -1) c = 'O';
			else if (board[i][j] == 1) c = 'X';
			else c = ' ';

			printf("%c ", c);
		}
		printf("\n");
	}
}

int main(void)
{
	int i, j;
	int x, y, count = 0;
	int board[3][3];
	char player;

	player = 'X'; // Player �ʱ�ȭ
	for (i = 0; i < 3; i++) // ���� �ʱ�ȭ
		for (j = 0; j < 3; j++)
			board[i][j] = 0;

	do {
		printf("Player %c(��, ��) : ", player);
		scanf("%d %d", &x, &y);
	
		if (board[x][y] != 0)
			continue;

		board[x][y] = (player == 'O') ? -1 : 1;
		print_board(board);
		count++;

		// �� �ٲٱ�
		player = (player == 'O') ? 'X' : 'O';
		}while (!win_check(x, y, board) && count < 9); 
	// �������� �̱�ų� ���尡 ��� ���õǾ� �������� �ݺ�
	 
	//�̹� ���� �ٲ�����Ƿ� 
	if (win_check(x, y, board))
		printf("Player %c wins!\n", player == 'X'? 'O':'X');
	else
		printf("Nobody wins.\n");
}
