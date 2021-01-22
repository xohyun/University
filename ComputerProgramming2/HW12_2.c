//HW12_2 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	FILE *fp1, *fp2;
	char ch;

	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");

	ch = getc(fp1);
	while(!feof(fp1))
	{
		putc(toupper(ch), fp2);
		ch = getc(fp1);
	}
	fprintf(fp2, "\n");

	fseek(fp1, 0, SEEK_SET);
	ch = getc(fp1);
	while(!feof(fp1))
	{
		putc(tolower(ch), fp2);
		ch = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}