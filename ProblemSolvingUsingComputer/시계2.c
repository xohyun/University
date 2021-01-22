#include <stdio.h>
static int count = 0;
void checkTime(int T[], int bucketSize)
{
	int i;

	for (i = 0; i < 16; i++)
		if (T[i] % 12 != 0)
			return;
	count = bucketSize;
	printf("%d\n", count);
	return;
}
void push(int a,int s[][16], int T[])
{
	int i;
	for (i = 0; i < 16; i++)
		if (s[a][i] == 1)
			T[i] +=  3;
	
	/*for (i = 0; i < 16; i++)
		printf("%d  ", T[i]);
	printf("\n");*/
}
void back(int a, int s[][16], int T[])
{
	int i;
	for (i = 0; i < 16; i++)
		if (s[a][i] == 1)
			T[i] -= 3;
}
void pick(int n, int bucket[], int bucketSize, int k, int s[][16], int T[])//n = 10
{
	int lastIndex, smallest, i, nn;
	if (count > 0) return;
	if (bucketSize > 40) return;
	if (k == 0)
	{
		/*for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");*/
		for (i = 0; i < bucketSize; i++)
			push(bucket[i], s, T);
		
		checkTime(T, bucketSize);
		
		for(i = 0; i < bucketSize; i++)
			back(bucket[i], s, T);
		
		return;
	}
	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];
	for (i = smallest; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1, s, T);
	}
}
int main(void)
{
	int bucket[10], time[16], total = 0;
	int s[10][16];
	int num, n, nn;
	int i, j;
	int b[30];
	
	for (i = 0; i < 10; i++)
		for (j = 0; j < 16; j++)
			s[i][j] = 0;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d %d", &nn, &num);
		for (j = 0; j < num; j++)
		{
			scanf("%d", &n);
			s[nn][n] = 1;
		}
	}

	for (i = 0; i < 16; i++)
		scanf("%d", &time[i]);

	for (i = 0; i < 16; i++)
		if (time[i] % 12 == 0)
			total++;
	
	if (total == 16) printf("0\n");
	else
		for(i = 1; i < 30; i++)
			pick(10, b, i, i, s, time);
}