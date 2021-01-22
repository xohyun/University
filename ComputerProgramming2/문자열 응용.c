#include <stdio.h>
int main(void)
{
	char word[80];
	int i, num = 0;

	printf("Enter a word");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++)
		// 여기에 코드를 삽입
		num = 10 * num + (word[i] - 48);
	printf("The number is %d\n", num);
}