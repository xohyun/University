//����1�б�⸻���(�迭 ����) 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int main(void)
{
	int a[10] = {1, 2, 3, 4, 5};
	int size = 5;//���� �迭�� ����ִ� ������ ����
	int num, i;
	int count;//3�� �ݺ��� ����

	for (count = 0; count < 3; count++)
	{
		printf("Enter a number:");
		scanf("%d", &num);

		for (i = size; i > 0; i--)
			a[i] = a[i-1];
		a[0] = num;
		size++;

		for (i = 0; i < size; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}