#include <stdio.h>
int main(void)
{
	FILE *fp;

	fp = fopen("hello.txt", "a");

	fprintf(fp, "Hi\nEveryone\n");
	fclose(fp);
}