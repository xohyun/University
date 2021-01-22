//20170988 ÇÑ¼ÒÇö
#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{
	char temp;

	if (s == e || s > e) return;

	temp = str[s];
	str[s] = str[e];
	str[e] = temp;

	reverse_string(str, s + 1, e - 1);
}
int main()
{
	char str[100];
	
	printf("Enter any string:");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("Reversed String is: %s", str);
	printf("\n");
	return 0;
}