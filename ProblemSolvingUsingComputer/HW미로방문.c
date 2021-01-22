#include <stdio.h>
#define WIDTH 10 
#define HEIGHT 10 
int screen[WIDTH][HEIGHT] = { 
	0, 0, 0,-1,-1,-1,-1,-1,-1,-1, 
	-1,-1, 0,-1,-1,-1,-1,-1,-1,-1, 
	-1, 0, 0, 0, 0, 0, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1, 0, 0, 0,-1, 0, 0, 0,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1, 
	-1,-1,-1,-1, 0,-1, 0,-1, 0,-1, 
	-1,-1,-1,-1, 0,-1,-1,-1, 0,-1, 
	-1,-1,-1,-1, 0, 0, 0, 0, 0, 0 
}; 
void flood_fill(int x, int y)
{
	static int count = 0;
	if (x < 0 || x >= 10 || y < 0 || y >= 10)
		return;
 	if (screen[x][y] == 0) 
	{ 
		screen[x][y] = ++count;

		flood_fill(x, y + 1); // 순환호출
		flood_fill(x + 1, y); // 순환호출
		flood_fill(x, y - 1); // 순환호출
		flood_fill(x - 1, y); // 순환호출 
	}
}
void display()
{
	int i, j;
	for(i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			printf("%3d", screen[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	printf("미로:\n");
	display();
	
	flood_fill(0, 0);
	printf("\n시작점을 (0,0)으로 한 미로방문(순서표기);\n");
	display();
}