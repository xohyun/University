//challenge6b 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
int main(void)
{
	char word[80];
	int i, j = 0, num = 0, remember = 0;

	printf("Enter a word: ");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= '0' && word[i] <= '9')
		{
			num = num * 10 + (word[i] - 48);
			if (word[i + 1] == '\0')
				remember += num;
		}
		
		else
		{
			remember += num;
			num = 0;
		}
	}
	printf("���� ���� ���� ���� %d\n", remember);
}


	//for (i = 0; word[i] != '\0'; i++)
	//{
	//	num = 0;
	//	for (j = 0; word[j] != '\0'; j++)
	//	{
	//		if (word[i] >= '0' && word[i] <= '9')
	//		{
	//			num = 10 * num + (word[i] - 48);
	//			i++;
	//		}
	//		else
	//			break;
	//	}
	//	remember += num;
	//}
	//printf("%d\n", remember);