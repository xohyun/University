//HW9_2 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char numbers[15];
	char birthYear[5] = "19";
	int averageAge;

	printf("�ֹε�Ϲ�ȣ �Է�('-'����):");
	gets(numbers);

	strncat(birthYear, numbers, 2);

	printf("����� %s�⵵ ���̱���\n", birthYear);
	if (numbers[7] == '1')
	{
		puts("���ں��̽ñ���.");
		averageAge = 77;
	}
	else
	{
		puts("���ں��̽ñ���.");
		averageAge = 84;
	}

	printf("��� ���� %d�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", averageAge, (atoi(birthYear) + averageAge));
}