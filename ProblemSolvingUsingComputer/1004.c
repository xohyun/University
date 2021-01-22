#include <stdio.h>
static int count = 0;
void checkTime(int T[], int bucket[])
{
	int i, total = 0;
	
	for (i = 0; i < 4; i++)
		if (T[i] % 12 != 0)
			return;

	for (i = 0; i < 10; i++)
		if (bucket[i] != 0)
			total += bucket[i];
	count = total;
	
	printf("%d\n", count);
	return;
}
void push(int a,int s[][4], int T[])
{
	int i;
	for (i = 0; i < 4; i++)
		if (s[a][i] == 1)
			T[i] +=  3;
}
void back(int a, int s[][4], int T[])
{
	int i;
	for (i = 0; i < 4; i++)
		if (s[a][i] == 1)
			T[i] -= 3;
}
void pick(int n, int bucket[], int bucketSize, int k, int s[][4], int T[])//n = 10
{
	int lastIndex, smallest, i;
	if (count > 0) return;

	if (k == 0)
	{
		/*for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");*/
		
		for (i = 0; i < bucketSize; i++)
			if (bucket[i] != 0) 
				push(i, s, T);
		
		checkTime(T, bucket);
		
		for(i = 0; i < bucketSize; i++)
			if (bucket[i] != 0)
				back(i, s, T);
		return;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (i = smallest; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1, s, T);
	}
}
int main(void)
{
	int time[4], total = 0;
	int s[10][4];
	int num, n;
	int i, j;
	int b[4];
	
	for (i = 0; i < 10; i++)
		for (j = 0; j < 4; j++)
			s[i][j] = 0;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d %d", &b[i], &num);
		for (j = 0; j < num; j++)
		{
			scanf("%d", &n);
			s[i][n] = 1;
		}
	}

	for (i = 0; i < 4; i++)
		scanf("%d", &time[i]);
	
	for (i = 0; i < 4; i++)
		if (time[i] % 12 == 0)
			total++;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}
	if (total == 4) printf("0\n");
	else
		pick(4, b, 10, 10, s, time);
}