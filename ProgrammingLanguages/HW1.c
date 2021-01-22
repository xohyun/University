// ����а� 1711840 �Ѽ���
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
	int counter; // ��ɾ� ����Ƚ��
	input();
	counter = interpret();
	printf("��ɾ� ���� Ƚ�� : %d", counter);
	print(counter, M, R);
	return 0;
}
int check(int a) // 3digit���� Ȯ���ϴ� �Լ�
{
	if (a >= 1000)
		a %= 1000;
	return a;
}
void input()
{
	int t, c = 0;
	scanf("%d", &M[c]);
	while (M[c] != 100) // �Է��� 100�� �� ����ȴ�.
	{
		scanf("%d", &M[++c]);
		M[c] = check(M[c]);
		if (M[c] < 0) // ������ ��� ��ȣ�� �ٲ��� �� ó���Ѵ�.
			M[c] = check(-M[c]);
	}
	return;
}
int interpret()
{
	int c = 1, PC = 0; // c : ���� ���� 100�� ��ɾ� �� �� �������� �� �� �����Ƿ� �ʱⰪ�� 1�� ����.
	int buffer;
	int opcode, op1, op2;

	for (PC = 0; M[PC] != 100; PC++)
	{
		// fetch + opcode, op1, op2 �Ҵ� (PC�� �������� �޸𸮿��� ��ɹ��� ������.)
		buffer = M[PC];
		opcode = buffer / 100;
		buffer %= 100;
		op1 = buffer / 10;
		buffer %= 10;
		op2 = buffer;

		// decode, execute
		// opcode���� 0,1,...9�� ��.
		switch (opcode)
		{
		case 1:
			if (op1 != 0 || op2 != 0) // 1nn �Է� ���� ó��(100 ������ 1nn)
			{
				printf("1nn �Է� �����Դϴ�.\n");
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
			else if (op1 == 0 && op2 == 0) // 000 �Է� ���� ó��
			{
				printf("000 �Է� �����Դϴ�.\n");
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
	printf("\n[�������� �� ���]\n");
	for (i = 0; i < 10; i++)
		printf("R[%d] = %d\n", i, R[i]);
}