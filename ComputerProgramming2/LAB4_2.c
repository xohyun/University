#include <stdio.h>
int sum_rec(int);
void main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("1���� %d������ ���� %d�Դϴ�,\n", n, sum_rec(n));
}
// ����Լ� �̿�
int sum_rec(int n)
{
	printf("n = %d�϶� �Լ� ���� \n", n);//
	if (n == 0) // �� �� �ڵ� ����
		return 0;
	else
		return n + sum_rec(n - 1);
}