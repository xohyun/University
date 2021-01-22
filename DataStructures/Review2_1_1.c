//20170988 �Ѽ���
#include <stdio.h>
#include <stdlib.h>

typedef struct Score {
	int midterm;
	int final;
}Score;

void printScore(Score *p)
{
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
}
Score *biggerScore(Score *p1, Score *p2)
{
	int a = p1->midterm + p1->final;
	int b = p2->midterm + p2->final;

	if(a > b)
		return p1;
	return p2;
}
Score *totalScore(Score *p1, Score *p2)
{
	Score *total;
	total = (Score*)malloc(sizeof(Score));
	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}
Score *createScore(int m, int f)
{
	Score *pp;
	pp = (Score *)malloc(sizeof(Score));
	pp->midterm = m;
	pp->final = f;

	return pp;
}

int main(void)
{
	Score *p1, *p2, *p3;
	
	p1 = (Score *)malloc(sizeof(Score));
	p2 = (Score *)malloc(sizeof(Score));
	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("----------------------------\n");
	printf("���� ������ ���� ����: \n");
	printScore(biggerScore(p1, p2));

	printf("----------------------------\n");
	printf("�� ������ �� ��: \n");
	printScore(totalScore(p1, p2));

	printf("----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}