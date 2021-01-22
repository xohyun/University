#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2;
	char buf[30];

	fp1 = fopen("hello.txt", "r");
	fp2 = fopen("hello2.txt", "w");
	fgets(buf, sizeof(buf), fp1);
	while(!feof(fp1))
	{
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	fseek(fp1, 0, SEEK_SET); 

	fgets(buf, sizeof(buf), fp1);
	while(!feof(fp1))
	{
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}
	fclose(fp1);
	fclose(fp2);
}