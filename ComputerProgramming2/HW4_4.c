//HW4_4 20170988 ��ǻ���а� 17�й� �Ѽ���
#include<stdio.h>
int comb(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int C10_5;
	C10_5 = comb(10,5);

	printf("C10_5 : %d\n", C10_5);
	return 0;
}