#include <stdio.h>
int main(void)
{
	FILE * fp1, *fp2;
	int score;
	fp1 = fopen("score.in", "r");
	if (fp1 == NULL)
	{
		printf("���� ���� �����Դϴ�!!!\n");
		return 1;
	}
	fp2 = fopen("score.out", "w");
	if (fp2 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}
	// �а� ó��(+9�� ����)�ؼ� ����

	fscanf(fp1, "%d", &score);
	while (!feof(fp1))
	{
		fprintf(fp2, "%d\n", score + 9);
		fscanf(fp1, "%d", &score);
	}
	fclose(fp1);
	fclose(fp2);
}