//HW9_1 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�

	int i, alpha_count = 0, digit_count = 0;

	printf("���ڿ��� �Է��ϼ���:");
	gets(string);

	for (i = 0; string[i] != '\0'; i++)
	{
		if (isalpha(string[i]))
		{
			alphaString1[alpha_count] = string[i];
			alpha_count++;
		}
		else
		{
			digitString[digit_count] = string[i];
			digit_count++;
		}
	}
	alphaString1[alpha_count] = '\0';
	digitString[digit_count] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	for (i = 0; alphaString1[i] != '\0'; i++)
	{
		if (isupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
		else
			alphaString2[i] = toupper(alphaString1[i]);
	}
	alphaString2[i] = '\0';
	strcat(alphaString1, digitString);
	strcpy(convertedString, alphaString1); 

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}