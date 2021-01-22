#include <stdio.h>
void stringConcat(char s1[], char s2[])
{
	int i, length;

	for (i = 0; s1[i] != '\0'; i++);
	length = i;
	for (i = 0; s1[i] != '\0'; i++)
		s1[length++] = s2[i];
	s1[length] = '\0';
}
int main(void)
{
	char fullName[20] = "Suehee";
	char lastName[20] = "Pak";
	stringConcat(fullName, " "); // Suehee뒤에 공백문자를붙인다.
	stringConcat(fullName, lastName); // 다시 Pak을 붙인다
	printf("%s\n", fullName);
}