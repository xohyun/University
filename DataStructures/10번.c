#include<stdio.h>
int recursive(int n)
{
	printf("%d\n", n);
	if(n < 1) return -1;
	else return (recursive(n - 3) + 1);
	
}
int main(void)
{
	int a = recursive(10);
	printf("%d\n", a);
}