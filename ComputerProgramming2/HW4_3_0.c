//HW4_3_0 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int twoPower(int x);
int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("2의 %d승은 %d이다\n", n, twoPower(n));
}
int twoPower(int x)
{
	if (x == 0)
		return 1;
	else
		return 2 * twoPower(x - 1);
}