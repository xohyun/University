//HW4_2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int fibo(int n);
int main(void)
{
	int n, idx;
	printf("��� �Ǻ���ġ �������� ����ұ��?(3���� ū ����):");
	scanf("%d", &n);
	for (idx = 0; idx < n; idx++)
	{
		printf("%d ", fibo(idx));
		if ((idx + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
int fibo(int n) // ��������� �������� �ʴ´�
{
	int i = 0, fn_1 = 0, fn_2 = 1, fn = 1;

	while (i < n)
	{
		fn = fn_1 + fn_2;
		fn_1 = fn_2;
		fn_2 = fn;
		i++;
	}
	return fn;
}