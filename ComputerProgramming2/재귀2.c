#include <stdio.h>
int search_binary(int a[], int key, int low, int high)
{  
   	int mid;
   	if (low <= high){
   		printf("test: (%d ~ %d)�� Ž��\n", low, high);
		mid = (low + high) / 2;
		printf("test: mid = %d\n", mid);

   		if (key == a[mid])    // Ž�� ����
			return mid;
      	else if (key < a[mid]) // ���� �κи���Ʈ Ž�� 
	   		return search_binary(a, key, low, mid-1);
      	else                   // ������ �κи���Ʈ Ž�� 
	   		return search_binary(a, key, mid+1, high);
   }
   return -1;        // Ž�� ����
}

int main(void)
{
	int a[10] = {2, 5, 7, 10, 12, 
		         13, 20, 25, 50, 55};

	int key = 7;
	printf("Ű %d�� %d��°�� �ִ�\n", key, search_binary(a, key, 0, 9));
}
