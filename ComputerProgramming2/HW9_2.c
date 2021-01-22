//HW9_2 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char numbers[15];
	char birthYear[5] = "19";
	int averageAge;

	printf("주민등록번호 입력('-'포함):");
	gets(numbers);

	strncat(birthYear, numbers, 2);

	printf("당신은 %s년도 생이군요\n", birthYear);
	if (numbers[7] == '1')
	{
		puts("남자분이시군요.");
		averageAge = 77;
	}
	else
	{
		puts("여자분이시군요.");
		averageAge = 84;
	}

	printf("평균 수명 %d를 더하면 %d까지 산다고 계산됩니다.\n", averageAge, (atoi(birthYear) + averageAge));
}