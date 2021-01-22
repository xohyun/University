//컴프1학기기말고사(배열 응용) 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
int main(void)
{
	int a[10] = {1, 2, 3, 4, 5};
	int size = 5;//현재 배열에 들어있는 원소의 개수
	int num, i;
	int count;//3번 반복을 위한

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