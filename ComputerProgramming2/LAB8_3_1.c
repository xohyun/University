//LAB8_3_1 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int stringLength(char *s)
{
	int length = 0;
	while (*s++)
		length++;

	return length;
}
void stringCopy(char *s1, const char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}
int main (void)
{
	char copied[500];
	char data1[] = "abcde";
	char data2[] = "ABCDEFGH";

	stringCopy(copied, data1);
	printf("ù��° ������ copied�� ���̿� ���� %d�� %s�̴�.\n", stringLength(copied), copied);
	stringCopy(copied, data2);
	printf("�ι�° ������ copied�� ���̿� ���� %d�� %s�̴�.\n", stringLength(copied), copied);
}