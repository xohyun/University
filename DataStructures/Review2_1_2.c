//20170988 한소현
#include <stdio.h>
#include <stdlib.h>

typedef struct Score {
	int midterm;
	int final;
}Score;

void printScore(Score *p)
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
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
	Score s1, s2;
	Score *p3;
	
	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("----------------------------\n");
	printf("둘중 성적이 좋은 점수: \n");
	printScore(biggerScore(&s1, &s2));

	printf("----------------------------\n");
	printf("두 성적의 총 합: \n");
	printScore(totalScore(&s1, &s2));

	printf("----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}