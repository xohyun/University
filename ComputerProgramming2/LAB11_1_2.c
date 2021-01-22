#include <stdio.h>
typedef struct {
	int midterm;
	int final;
}Score;
void printScore(Score *p) 
{
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
} // �Ű����� ����
void *biggerScore(Score *p1, Score *p2) 
{
	if (p1->midterm > p2->midterm)
		return p1;
	else
		return p2;
} // ��ȯŸ�� ����, �Ű����� ����
void totalScore(Score *p1, Score *p2, Score *tp) 
{
	tp->midterm = p1->midterm + p2->midterm;
	tp->final = p1->final + p2->final;
} // ��ȯŸ�� ����, �Ű����� �� �� �߰�
Score createScore(int m, int f) 
{
	Score temp;
	temp.midterm = m;
	temp.final = f;
	return temp;
} // ������� ����!

// main�Լ��� �Ʒ��� ���� ����ȴ�.
int main(void) {
	Score s1, s2, temp;

	s1.midterm = 50; s1.final = 100;
	s2.midterm = 70; s2.final = 70;

	printf("1)-----------------------------\n");
	printScore(&s1);
	printScore(&s2);

	printf("2)-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("3)-----------------------------\n");
	printf("�� ������ �� ��:\n");
	totalScore(&s1, &s2, &temp);
	printScore(&temp);

	printf("4)-----------------------------\n");
	temp = createScore(99, 99);
	printScore(&temp);
}