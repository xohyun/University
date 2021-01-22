#include <stdio.h>
int main(void)
{
	int state;
	FILE * fp;
	char ch;

	fp = fopen("hello.out","w");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fp = fopen("hello.in", "r");

	ch = getc(fp);
	while (!feof(fp))
	{
		putc(ch, stdout);
		ch = getc(fp);
	}

	state = fclose(fp);
	if (state != 0) // 이 체크는 생략 가능
	{
		printf("file close error!\n");
		return 1;
	}
	
}