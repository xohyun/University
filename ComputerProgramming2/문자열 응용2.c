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
	stringConcat(fullName, " "); // Suehee�ڿ� ���鹮�ڸ����δ�.
	stringConcat(fullName, lastName); // �ٽ� Pak�� ���δ�
	printf("%s\n", fullName);
}