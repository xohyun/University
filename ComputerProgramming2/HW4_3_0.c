//HW4_3_0 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int twoPower(int x);
int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("2�� %d���� %d�̴�\n", n, twoPower(n));
}
int twoPower(int x)
{
	if (x == 0)
		return 1;
	else
		return 2 * twoPower(x - 1);
}