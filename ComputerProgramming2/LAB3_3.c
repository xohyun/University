//LAB3_3 20170988 컴퓨터학과 17학번 한소현
#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>

// set 에 element 가 있으면 1 을 없으면 0 을 반환한다
int hasElement(int set[], int size, int element)
{
	int i;
	for( i = 0; i < size; i++ )
		if( set[i] == element )
			return HAVE_ELEMENT; // we found it!
	return DO_NOT_HAVE_ELEMENT;
}
void printSet(int set[], int size)	
{
	int i;

	printf("{ ");
	for (i = 0; i < size; i++)
	{
		if (i < size - 1)
			printf("%d, ", set[i]);
		else
			printf("%d ", set[i]);
	}
	printf("}\n");
}

// set1 과 set2 가 같으면 1 을 다르면 0 을 반환
int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	int i;

	if (size1 != size2)
		return 0;
	
	for (i = 0; i < size1; i++)
		if (hasElement(set2, size1, set1[i]) == 0)
			return 0;
	return 1;
}

// 원소가 집합에 존재하지 않으면 추가, 이미 존재하면 redundant 라고 출력하고 현재 집합 크기를 반환
int addOneElement(int set[], int size, int element)
{
	if (hasElement(set, size, element) == 1)
		printf("It is redundant. Please retry.\n");
	else
	{
		set[size] = element;
		size++;
	}

	return size;
}

int main(void)
{
	int setA[MAX_SET_SIZE] ={1, 2, 3};
	int setB[MAX_SET_SIZE] = {3, 2, 1, 4};
	int num;
	int sizeA = 3, sizeB = 4;
	printf("A:"); printSet(setA, sizeA);
	printf("B:"); printSet(setB, sizeB);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("집합A 와 B 는 같다\n");
	else
		printf("집합 A 와 B 는 다르다\n\n");
	
	printf("A에 3을 추가하면\n");
	sizeA = addOneElement(setA, sizeA, 3); // 3 을 SetA 에 추가한다
	printf("집합 A:"); printSet(setA, sizeA);
	printf("A에 4를 추가하면\n");
	sizeA = addOneElement(setA, sizeA, 4); // 4 를 SetA 에 추가한다
	printf("집합 A:"); printSet(setA, sizeA);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("집합 A 와 B 는 같다\n");
	else
		printf("집합 A 와 B 는 다르다\n");
}