#include <stdio.h>
int main(void)
{
	char c = 'A';
	int n = 100;
	double d = 3.14;

	char *pC;
	int *pN;
	double *pD;

	pC = &c;
	pN = &n;
	pD = &d;

	printf("%c %d %c\n", c, pC, *pC);
	printf("%d %d %d\n", n, pN, *pN);
	printf("%lf %d %lf\n", d, pD, *pD);

	// c, pC, *pC, n, pN, *pN, d, pD, *pD에 어떤 수가 들어가나 예상 후
	// 조사식창에 위의 이름들을 입력하여 확인
	// c: _____________ pC:__________________ *pC________________
	// n: _____________ pN:__________________ *pN________________
	// d: _____________ pD:__________________ *pD________________

	*pC = 'Z';
	*pN = 199;
	*pD = 3.1415;

	pC++;
	pN++;
	pD++;
	// pC, pN, pD의 값이 어떻게 바뀌었는가?
	// pC: ______________ pN:___________________ pD:_________________

	printf("%d %d %d\n", pC, pN, pD);

	pC = pC + 2;
	pN = pN + 2;
	pD = pD + 2;
	// pC, pN, pD의 값이 어떻게 바뀌었는가?
	// pC: ______________ pN:___________________ pD:_________________
	printf("%d %d %d\n", pC, pN, pD);
}

