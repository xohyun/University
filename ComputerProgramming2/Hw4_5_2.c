//HW4_5_2 20170988 컴퓨터학과 17학번 한소현
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
	printf("%d ", n);
	if(n != 1)
	{
		if(n % 2 == 0)
			return 1 + get_cycle_number(n / 2);
		else
			return 1 + get_cycle_number(n * 3 + 1);
	}
	else
		return 1;
}