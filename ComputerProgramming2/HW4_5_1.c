//HW4_5_1 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
	int num;

	printf("수를 입력하시오 : ");
	scanf("%d", & num);

	printf("\n사이즈는 : %d\n", get_cycle_number(num));
}
int get_cycle_number(int n)
{
	int count = 1;
	printf("%d ", n);

	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		
		printf("%d ", n);
		count++;
	}
	return count;
}