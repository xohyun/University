#include <stdio.h>
int main(void)
{
	int state;
	FILE * fp;
	char ch;
	fp = fopen("hello.in", "r");
	if (fp == NULL)
	{
		printf("���� ���� �����Դϴ�!!!\n");
		return 1;
	}
	// getc, putc�� ����Ͽ� ������ ������ �а� ����
	ch = getc(fp);
	while (!feof(fp))
	{
		putc(ch, stdout);
		ch = getc(fp);
	}
	fclose(fp);
	return 0;
}