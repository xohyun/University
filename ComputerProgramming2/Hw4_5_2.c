//HW4_5_2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
	int num;

	printf("���� �Է��Ͻÿ� : ");
	scanf("%d", & num);

	printf("\n������� : %d\n", get_cycle_number(num));
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