//challenge6d2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#define MAX_STRING 81
#define BOOL int
#define TRUE 1
#define FALSE 0

// Palindrome �˻�
BOOL isPalindrome(char str[]);
int main(void)
{
	char str[MAX_STRING];

	printf("* Palindrome üũ\n\n");
	printf("���ڿ� �Է�(���ڼ� %d ����): ", MAX_STRING);
	scanf("%s", str);

	if (isPalindrome(str)) // Palindrome �˻�
		printf("\"%s\" is a Palindrome\n\n", str); // ���� ����Ϸ��� \���� ���
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);
	return 0;
}
BOOL isPalindrome(char s[])
{
	//���ڿ� s��(����� s�� ������������, �̴� 2�б⶧ ����)
	//üũ�ؼ� palindrome�̸� TRUE���� palindrome�ƴϸ� FALSE���� return�Ѵ�.
	int i, length;

	for (i = 0; s[i] != '\0'; i++);
	length = i;
	
	for (i = 0; i < length / 2; i++)
		if (s[i] != s[length - 1 - i])
			return FALSE;
	return TRUE;
}