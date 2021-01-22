#include <stdio.h>// 중복순열
void pick(int n, int bucket[], int bucketSize, int k)
{
	int lastIndex, i, smallest;

	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k) smallest = 0;
	else
		smallest = bucket[lastIndex];
	for(i = smallest; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int bucket[3];
	int s[3][3], i, j;
	pick(4, bucket, 3, 3);
	/*for (i = 0; i < 3; i++)
		scanf("%d", &s[i]);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}*/
}