#include <stdio.h>
int main(void)
{
	int i, j = 0;

	char word[80], newWord[80] ;

	printf("Enter a word: ");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++)
		if (word[i] >= '0' && word[i] <= '9')
			newWord[j++] = word[i];
	newWord[j] = '\0';

	printf("The digits are %s\n", newWord);
}