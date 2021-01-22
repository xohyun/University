//HW4_2 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int fibo(int n);
int main(void)
{
	int n, idx;
	printf("몇개의 피보나치 수열값을 출력할까요?(3보다 큰 정수):");
	scanf("%d", &n);
	for (idx = 0; idx < n; idx++)
	{
		printf("%d ", fibo(idx));
		if ((idx + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
int fibo(int n) // 재귀적으로 구현하지 않는다
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