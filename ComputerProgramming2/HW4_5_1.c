//HW4_5_1 20170988 ��ǻ���а� 17�й� �Ѽ���
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