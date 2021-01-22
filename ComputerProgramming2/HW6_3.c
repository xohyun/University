//컴퓨터학과 1학년 한소현

#include <stdio.h>
#include <stdio.h>
int main(void)
{
	char word[81], newWord[81];
	int i, length;

	printf("Enter one word: ");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++);
	length = i;

	for (i = 0; i < length; i++)
		newWord[length - 1 - i] = word[i];
	newWord[length] = '\0';

	printf("%The reversed word is %s\n", newWord);
}