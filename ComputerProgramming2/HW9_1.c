//HW9_1 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50]; // 입력되는 문자열을 저장
	char alphaString1[50]; // 입력문자열에서 알파벳만 저장
	char alphaString2[50]; // 대소문자를 바꿈
	char digitString[50];
	char convertedString[50]; // 문자들과 숫자들로 재배열한 문자열

	int i, alpha_count = 0, digit_count = 0;

	printf("문자열을 입력하세요:");
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

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

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

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
}