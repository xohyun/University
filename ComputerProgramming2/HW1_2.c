//HW1_2 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int main(void)
{
	int coins[4] = {500, 100, 50, 10};
	int change, i, count;

	printf("Enter the amount of change: ");
	scanf("%d", &change);

	for (i = 0; i < 4; i++)
	{
		count = change / coins[i];
		printf("%d coin: %d\n", coins[i], count);
		change = change % coins[i];
	}
}