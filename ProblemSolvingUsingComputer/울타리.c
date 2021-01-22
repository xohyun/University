#include <stdio.h>
#include <stdlib.h>
int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int Min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}
int wantMax(int a, int b, int c)
{
	int big;
	if (a > b)
		big = a;
	else 
		big = b;

	if (big < c)
		big = c;
	return big;
}
int center_area(int h[], int l, int r)
{
	int mid, Min_H, Max_area, row = 1, LO;
	int HI;

	mid = (l + r) / 2;
	HI = mid + 1;
	LO = mid;

	if (h[LO] < h[HI])
		Min_H = h[HI];
	else
		Min_H = h[LO];

	Max_area = Min_H;
	while (HI < (r + 1) || LO > (l - 1))
	{
		if (h[HI] > h[LO])
		{
			Min_H = Min(Min_H, h[HI]);
			Max_area = Max(Max_area, row*Min_H);
			HI++;
		}

		else 
		{
			Min_H = Min(Min_H, h[LO]);
			Max_area = Max(Max_area, row*Min_H);
			LO--;
		}

		row++;
	}
	printf("!!!!!!!!!!!!!! %d\n", Max_area);
	return Max_area;
}
int max_area(int h[], int l, int r)
{
	int l_area, r_area, c_area, maxArea;
	int mid;

	if (l == r) return h[l];

	mid = (l + r) / 2;
	l_area = max_area(h, l, mid);
	r_area = max_area(h, mid + 1, r); 

	c_area = center_area(h, l, r);
	printf("+++%d\n", c_area);
	maxArea = wantMax(l_area, r_area, c_area);

	printf("////%d\n", maxArea);
	return maxArea;
}
int main(void)
{
	int *h, num, i, a;

	scanf("%d", &num);
	h = (int*)malloc(sizeof(int) * num);

	for (i = 0; i < num; i++)
		scanf("%d", &h[i]);

	a = max_area(h, 0, num - 1);
	printf("%d\n", a);
	free(h);
}