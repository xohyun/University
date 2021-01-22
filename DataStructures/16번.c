#include <stdio.h>
int fib(int n)
{
	printf("fib(fib(%d) is called\n", n);
	if( n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
int main(void)
{
	//int a = fib(6);
	//printf("****%d\n", a);
	printf("<%d>\n", fib(0));
	printf("<%d>\n", fib(1));
	printf("<%d>\n", fib(2));
	printf("<%d>\n", fib(3));
	printf("<%d>\n", fib(4));
	printf("<%d>\n", fib(5));
	printf("<%d>\n", fib(6));
}