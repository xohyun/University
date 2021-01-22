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
	char delimiters[] = " ,\n\0"; // �� ���� �и� ���ڵ�(����,�޸�,�ٹٲ�,�ι���) �����Ѵ�
	char *token;

	printf("��)str1 �� ���� = %d\n", strlen(str1));
	printf(" str2 �� ���� = %d\n", strlen(str2));

	strcpy(str1, str2);
	printf("��)str1 = %s\t\tstr2 = %s\n", str1, str2);

	strncpy(str1, str3, 2); // 2 ���� ���ڸ� ������ �� null ���ڴ� ���� �ʴ� �Ϳ� ��������.
	printf("��)str1 = %s\t\tstr3 = %s\n", str1, str3);

	strcat(str1, str2);
	printf("��)str1 = %s\tstr2 = %s\n", str1, str2);

	strncat(str1, str3, 2); // �̶� null ���ڸ� �߰��� �ִ´�!
	printf("��)str1 = %s\tstr3 = %s\n", str1, str3);

	printf("��)%d %d %d\n", strcmp("aaa", "abc"), strcmp("aaa", "aaa"), strcmp("ddd", "ccc", str3));

	strcpy(str1, "111");
	n = atoi(str1) * 7;
	printf("��)str3 �� 7 �� �� ���� %d\n", n);

	printf("��)\n");
	n = 1;
	token = strtok(s, delimiters);
	while (token != NULL)
	{
		printf("%d ��° ��ū�� %s\n", n++, token);
		token = strtok(NULL, delimiters);
	}
}