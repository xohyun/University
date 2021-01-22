//컴프1학기기말고사(배열의 일부로 다른배열 만들기) 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
void printArray(int a[], int size);
int main(void)
{
	int i;
	int list[10] = {1,3,4,5,7,8,9,10,11,12};
	int evenList[10];//짝수들을 담을 배열
	int k = 0;

	for (i = 0; i < 10; i++)
		if (list[i] % 2 == 0)
		{
			evenList[k] = list[i];
			k++;
		}

	printArray(evenList, k);
}
void printArray(int a[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	return;
}