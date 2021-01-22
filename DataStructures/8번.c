#include <stdio.h>
int sum(int n)
{
	printf("%d\n", n);
	if(n < 1) return 1;
	else return (n + sum(n - 1));
}
int main(void)
{
	int a = sum(5);
	printf("%d\n", a);
}