#include <stdio.h>
int checkTime(int T[], int bucket[], int count)
{
	int i;
	int static total = 0;
	if (count > 0) return count;
	if (total > 0) return count;
	for (i = 0; i < 16; i++)
		if (T[i] % 12 != 0)
		{
			return count;
		}
	printf("한개라도?\n");
	for (i = 0; i < 10; i++)
		if (bucket[i] != 0)
			total += bucket[i];
	count = total;
	
	printf("%d\n", count);
	return count;
}
void push(int a,int s[][16], int T[],int flag)
{
	int i;
	if (flag == 1)
	{
		for (i = 0; i < 16; i++)
			if (s[a][i] == 1)
				T[i] +=  3;
		printf("* *");
	}
	else
	{
		for (i = 0; i < 16; i++)
			if (s[a][i] == 1)
				T[i] -=  3;
	}
	
	for (i = 0; i < 16; i++)
			printf("%3d", T[i]);
		printf("\n");
}
/*void back(int a, int s[][16], int T[])
{
	int i;
	for (i = 0; i < 16; i++)
		if (s[a][i] == 1)
			T[i] -= 3;
	for (i = 0; i < 16; i++)
			printf("%3d", T[i]);
		printf("\n");
	printf("=======================================================\n");
}*/
void pick(int n, int bucket[], int bucketSize, int k, int s[][16], int T[])//n = 10
{
	int lastIndex, smallest, i;
	static int count = 0;

	//printf("------------------------------%d\n", count);
	if (count > 0){
		
		return;
	}

	if (k == 0)
	{
		/*for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");*/
		
		for (i = 0; i < bucketSize; i++)
			if (bucket[i] != 0) 
			{
				push(i, s, T, 1);
			}
		
		count = checkTime(T, bucket, count);
		printf("들어가요?\n");
		for(i = 0; i < bucketSize; i++)
			if (bucket[i] != 0)
			{
				push(i, s, T, 0);
			}
		
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
	int time[16], total = 0;
	int s[10][16];
	int num, n, nn;
	int i, j;
	int b[10];
	
	for (i = 0; i < 10; i++)
		for (j = 0; j < 16; j++)
			s[i][j] = 0;


	/*count = 1;
	printf("%d\n\n", count);
	checking();
	count++;
	checking();*/
	/*
	printf("안녕?");
	for (i = 0; i < 16; i++)
	{
		time[i] = 12;
		//b[i] = 1;
		printf("%d %d\n", time[i], i);
	}
	for (i = 0; i < 10; i++)
		b[i] = 1;

	checkTime(time, b);
	
	*/

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
		pick(4, b, 10, 10, s, time);
}