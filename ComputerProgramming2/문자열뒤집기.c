#include <stdio.h>
void reverseString(char s[])
{
	int i, length;
	int temp;

	for (i = 0; s[i] != '\0'; i++);
	length = i;

	for (i = 0; s[i] < length / 2; i++)
	{
		temp = s[length - 1 - i];
		s[length - 1 - i] = s[i];
		s[i] = temp;
	}
}

int main(void)
{
	char word[20];

	printf("Enter a string:");
	scanf("%s", word);

	reverseString(word);
	printf("%s\n", word);
}