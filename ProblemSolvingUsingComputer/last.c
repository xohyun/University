#include <stdio.h>
void print(int a[])
{
	int i;
	for (i = 0; i < 16; i++)
		printf("%3d", a[i]);
	printf("\n");
}
void pick(int n, int bucket[], int bucketSize, int k, int s[][16], int T[])//n = 10
{
	int lastIndex, smallest, i, temp[16], j, total = 0, num, r;
	static int count = 0;

	//printf("------------------------------%d\n", count);
	if (count > 0){
		return;
	}

	for (i = 0; i < 16; i++)
		temp[i] = T[i];

	if (k == 0)
	{
		/*for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");*/


		//printf("Ã¹:");
		//print(temp);

		/*for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		*/
		for (i = 0; i < bucketSize; i++)
		{
			num = bucket[i];
			for (r = 0; r < num; r++)
			{
				for(j = 0; j < 16; j++)
					if(s[i][j]) temp[j] += 3;
			}
		}
		//printf("³¡:");
		//print(temp);

		//printf("\n");

		for (i = 0; i < 16; i++)
			if(temp[i] % 12 != 0) return;

			
		//printf("µé¾î°¬´Ï?\n");
		count++;
		for (i = 0; i < 10; i++)
			total += bucket[i];
		printf("%d\n", total);
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
	printf("¾È³ç?");
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