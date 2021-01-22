#include <stdio.h>
int checkTime(int T[])
{
	int i;

	for (i = 0; i < 16; i++)
		if (T[i] % 12 != 0)
			return 0;
	return 1;
}
void push(int a,int s[][16], int T[])
{
	int i;
	for (i = 0; i < 16; i++)
		if (s[a][i] == 1)
			T[i] +=  3;
	
	for (i = 0; i < 16; i++)
		printf("%d  ", T[i]);
	printf("\n");
}
void back(int a, int s[][16], int T[])
{
	int i;
	for (i = 0; i < 16; i++)
		if (s[a][i] == 1)
			T[i] -= 3;
}
int pick(int n, int bucket[], int bucketSize, int k, int s[][16], int T[])//n = 10
{
	int lastIndex, smallest, i, nn;
	if (bucketSize >30) return 0;
	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		for (i = 0; i < bucketSize; i++)
			push(bucket[i], s, T);
		
		if (checkTime(T)){
			printf("*******%d************************************\n", bucketSize);
			return bucketSize;
		}
		else
		{
			for(i = 0; i < bucketSize; i++)
				back(bucket[i], s, T);
		}
		return 0;
	}
	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];
	for (i = smallest; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		nn = pick(n, bucket, bucketSize, k - 1, s, T);
		if (nn > 0 && nn != 10) 
		{
			printf("<%d>\n", nn);
			break;
		}
	}
}
int main(void)
{
	int bucket[10], time[16];
	int s[10][16];
	int num, n;
	int i, j;
	int b[10];
	
	for (i = 0; i < 10; i++)
		for (j = 0; j < 16; j++)
			s[i][j] = 0;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d %d", &bucket[i], &num);
		for (j = 0; j < num; j++)
		{
			scanf("%d", &n);
			s[i][n] = 1;
		}
	}


	for (i = 0; i < 16; i++)
		scanf("%d", &time[i]);
	

	n = pick(10, b, 2, 2, s, time);
	if (n > 0) printf("%d\n", n);
	/*for(i = 1; i <= 10; i++)
	{
		n = pick(10, b, i, i, s, time);
		if(n > 0)
			printf("%d\n", n);
	}*/
	//bucketSize를 움직여서받아야해.
}