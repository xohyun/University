//LAB8_3_2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int stringEqual(const char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
		if (*s1++ != *s2++)
			return 1;

	return 0;
}
void main()
{
	char string1[50];
	char string2[50];

	printf("Enter the first string:");
	scanf("%s", string1);
	printf("Enter the second string:");
	scanf("%s", string2);

	if (stringEqual(string1, string2) == 0)
		printf("�ΰ��� ���ڿ��� ����\n");
	else
		printf("�ΰ��� ���ڿ��� �ٸ���\n");
}