#include <stdio.h>
void asterisk(int i)
{
	if (i >  1)
	{
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
}
int main(void)
{
	asterisk(5);
}