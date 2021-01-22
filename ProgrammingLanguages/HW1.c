// 통계학과 1711840 한소현
#pragma warning(disable : 4996)
#include <stdio.h>
int M[1000] = { 0 };
int R[10] = { 0 };
void input();
int interpret();
void print(int counter, int *M, int *R);
int check(int a);
int main()
{
	int counter; // 명령어 실행횟수
	input();
	counter = interpret();
	printf("명령어 실행 횟수 : %d", counter);
	print(counter, M, R);
	return 0;
}
int check(int a) // 3digit인지 확인하는 함수
{
	if (a >= 1000)
		a %= 1000;
	return a;
}
void input()
{
	int t, c = 0;
	scanf("%d", &M[c]);
	while (M[c] != 100) // 입력이 100일 때 종료된다.
	{
		scanf("%d", &M[++c]);
		M[c] = check(M[c]);
		if (M[c] < 0) // 음수인 경우 부호를 바꿔준 후 처리한다.
			M[c] = check(-M[c]);
	}
	return;
}
int interpret()
{
	int c = 1, PC = 0; // c : 종료 조건 100도 명령어 한 번 실행으로 볼 수 있으므로 초기값을 1로 설정.
	int buffer;
	int opcode, op1, op2;

	for (PC = 0; M[PC] != 100; PC++)
	{
		// fetch + opcode, op1, op2 할당 (PC값 기준으로 메모리에서 명령문을 가져옴.)
		buffer = M[PC];
		opcode = buffer / 100;
		buffer %= 100;
		op1 = buffer / 10;
		buffer %= 10;
		op2 = buffer;

		// decode, execute
		// opcode값이 0,1,...9일 때.
		switch (opcode)
		{
		case 1:
			if (op1 != 0 || op2 != 0) // 1nn 입력 오류 처리(100 제외한 1nn)
			{
				printf("1nn 입력 오류입니다.\n");
				c--;
			}
			break;
		case 2:
			R[op1] = op2;
			break;
		case 3:
			R[op1] = R[op1] + op2;
			R[op1] = check(R[op1]);
			break;
		case 4:
			R[op1] = R[op1] * op2;
			R[op1] = check(R[op1]);
			break;
		case 5:
			R[op1] = R[op2];
			break;
		case 6:
			R[op1] = R[op1] + R[op2];
			R[op1] = check(R[op1]);
			break;
		case 7:
			R[op1] = R[op1] * R[op2];
			R[op1] = check(R[op1]);
			break;
		case 8:
			R[op1] = M[op2];
			R[op1] = check(R[op1]);
			break;
		case 9:
			M[op2] = R[op1];
			M[op2] = check(M[op2]);
			break;
		case 0:
			if (R[op2] != 0)
			{
				PC = R[op1];
				PC--;
				c++;
				continue;
			}
			else if (op1 == 0 && op2 == 0) // 000 입력 오류 처리
			{
				printf("000 입력 오류입니다.\n");
				c--;
			}
			break;
		default:
			break;
		}
		c++;
	}
	return c;
}
void print(int counter, int *M, int *R)
{
	int i;
	printf("\n[레지스터 값 출력]\n");
	for (i = 0; i < 10; i++)
		printf("R[%d] = %d\n", i, R[i]);
}