#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str1[15] = "ABCDED";
	char str2[15] = "abcde";
	char str3[15] = "1234";
	int n;

	char s[] = "Life is short, but art is long";
	char delimiters[] = " ,\n\0"; // 네 개의 분리 문자들(공백,콤마,줄바꿈,널문자) 지정한다
	char *token;

	printf("가)str1 의 길이 = %d\n", strlen(str1));
	printf(" str2 의 길이 = %d\n", strlen(str2));

	strcpy(str1, str2);
	printf("나)str1 = %s\t\tstr2 = %s\n", str1, str2);

	strncpy(str1, str3, 2); // 2 개의 문자를 복사할 때 null 문자는 넣지 않는 것에 주의하자.
	printf("다)str1 = %s\t\tstr3 = %s\n", str1, str3);

	strcat(str1, str2);
	printf("라)str1 = %s\tstr2 = %s\n", str1, str2);

	strncat(str1, str3, 2); // 이때 null 문자를 추가로 넣는다!
	printf("마)str1 = %s\tstr3 = %s\n", str1, str3);

	printf("바)%d %d %d\n", strcmp("aaa", "abc"), strcmp("aaa", "aaa"), strcmp("ddd", "ccc", str3));

	strcpy(str1, "111");
	n = atoi(str1) * 7;
	printf("사)str3 를 7 배 한 값은 %d\n", n);

	printf("아)\n");
	n = 1;
	token = strtok(s, delimiters);
	while (token != NULL)
	{
		printf("%d 번째 토큰은 %s\n", n++, token);
		token = strtok(NULL, delimiters);
	}
}