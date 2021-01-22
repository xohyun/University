//HW7_1 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#include <stdlib.h>

void generateData();
void printData();
int totalData();
int maxData();
int data[10]; // ��� ���࿡ ����� ���� ����

int main(void)
{
	srand(time(NULL));
	generateData();
	printf("�߻��� 10���� ����:\n");
	printData();
	printf("10�� ������ �� = %d \n", totalData());
	printf("10�� ������ ���� ū �� = %d \n", maxData());
}

void generateData()
{
	int k;
	int *p;
	p = data; //Ȥ�� p = &data[0]
	for (k = 0; k < 10; k++) // Index 0..9���� ������ �ο�
		*p++ = rand() % 100;
}

// printData �Լ��� data[0]..data[9]�� ���� ����Ѵ�.
void printData()
{
	int *pi = data;
	int i;

	for (i = 0; i < 10; i++)
		printf("%d ", *pi++);
	printf("\n");
}

// totalData �Լ��� data[0]���� data[9]������ ���� ��� ���� �� ����� ��ȯ�Ѵ�.
int totalData()
{
	int *pi = data, sum = 0;
	int i;

	for (i = 0; i < 10; i++)
		sum += *pi++;
	return sum;
}

int maxData()
{
	int max = -99, i;
	int *pi = data;

	for (i = 0; i < 10; i++)
	{
		if (max < *pi)
			max = *pi;
		pi++;
	}
	return max;
}