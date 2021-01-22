#include <stdio.h>
int search_binary(int a[], int key, int low, int high)
{  
   	int mid;
   	if (low <= high){
   		printf("test: (%d ~ %d)를 탐색\n", low, high);
		mid = (low + high) / 2;
		printf("test: mid = %d\n", mid);

   		if (key == a[mid])    // 탐색 성공
			return mid;
      	else if (key < a[mid]) // 왼쪽 부분리스트 탐색 
	   		return search_binary(a, key, low, mid-1);
      	else                   // 오른쪽 부분리스트 탐색 
	   		return search_binary(a, key, mid+1, high);
   }
   return -1;        // 탐색 실패
}

int main(void)
{
	int a[10] = {2, 5, 7, 10, 12, 
		         13, 20, 25, 50, 55};

	int key = 7;
	printf("키 %d는 %d번째에 있다\n", key, search_binary(a, key, 0, 9));
}
