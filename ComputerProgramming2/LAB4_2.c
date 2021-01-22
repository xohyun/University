#include <stdio.h>
int sum_rec(int);
void main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("1부터 %d까지의 합은 %d입니다,\n", n, sum_rec(n));
}
// 재귀함수 이용
int sum_rec(int n)
{
	printf("n = %d일때 함수 시작 \n", n);//
	if (n == 0) // 이 곳 코드 삽입
		return 0;
	else
		return n + sum_rec(n - 1);
}