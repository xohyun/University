#include <stdio.h>
#define SIZE 5

void search(int a[], int key, int left, int right)
{
	int mid; 
	if (left > right) return;

	mid = (left + right) / 2;
	if (a[mid] == key) printf("키 %d가 인덱스 %d에 있음\n", key, mid);
	search(a, key, left, mid-1);
	search(a, key, mid+1, right);
}
int main(void)
{
	int a[10] = {10, 7, 5, 8, 7, 
		         7, 13, 7, 50, 7};

	int key = 7;
	search(a, key, 0, 9);
}
