//�����нð� 20170988 ��ǻ���а� 17�й� �Ѽ���
#include <stdio.h>
#define MAX_NUMBERS 10
void printTopTier( int num[], int numSize ); // ù ��° ���� ����ϴ� �Լ�
void printSecondTier( int num[], int numSize ); // �� ��° ���� ����ϴ� �Լ�
void printMiddleTier( int num[], int numSize ); //�� ��° ���� ����ϴ� �Լ�
void printFourthTier( int num[], int numSize ); // �� ��° ���� ����ϴ� �Լ�
void printBottomTier( int num[], int numSize ); // ù ��° ���� ����ϴ� �Լ�
int main(void)
{
	int numbers[MAX_NUMBERS];
	int sizeOfNumbers;
	int i = 0;
	printf("Enter the input size:");
	scanf("%d",&sizeOfNumbers);
	while( i < sizeOfNumbers )
	{
		printf("Enter the number (%d/%d):", i+1,sizeOfNumbers );
		scanf( "%d", &numbers[i] );
		if ( numbers[i] >= 10 || numbers[i] < 0 )
		{
			printf("Error: You must enter one decimal digit.(0<= input < 10 )\n" );
		}
		else
		{
			i++;
		}
	}
	printf( "\n\n" );
	printTopTier( numbers, sizeOfNumbers );
	printSecondTier( numbers, sizeOfNumbers );
	printMiddleTier( numbers, sizeOfNumbers );
	printFourthTier( numbers, sizeOfNumbers );
	printBottomTier( numbers, sizeOfNumbers );
	printf( "\n\n" );
}
void printTopTier( int num[], int numSize )
{
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // �� ���ڸ� ����ϱ� ���� ù ��° �� ���
		{
			case 1:
			case 4:
				printf( "   " );
				break;
			default :
				printf( " - " );
				break;
		}
		printf( " " ); // ���� ������ ���� (�� ĭ�� space�� �̿�)
	}
	printf("\n");
}
void printSecondTier( int num[], int numSize )
{
	// �����ؾ� �� �Լ�
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // �� ���ڸ� ����ϱ� ���� ù ��° �� ���
		{
			case 1:
			case 2:
			case 3:
			case 7:
				printf( "  |" );
				break;
			case 5:
			case 6:
				printf( "|  " );
				break;
			default :
				printf( "| |" );
				break;
		}
		printf( " " ); // ���� ������ ���� (�� ĭ�� space�� �̿�)
	}
	printf("\n");

}
void printMiddleTier( int num[], int numSize )
{
	// �����ؾ� �� �Լ�
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // �� ���ڸ� ����ϱ� ���� ù ��° �� ���
		{
			case 1:
			case 7:
			case 0:
				printf( "   " );
				break;
			default :
				printf( " - " );
				break;
		}
		printf( " " ); // ���� ������ ���� (�� ĭ�� space�� �̿�)
	}
	printf("\n");
}
void printFourthTier( int num[], int numSize )
{
	// �����ؾ� �� �Լ�
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // �� ���ڸ� ����ϱ� ���� ù ��° �� ���
		{
			case 2:
				printf( "|  " );
				break;
			case 6:
			case 8:
			case 0:
				printf( "| |" );
				break;
			default :
				printf( "  |" );
				break;
		}
		printf( " " ); // ���� ������ ���� (�� ĭ�� space�� �̿�)
	}
	printf("\n");
}
void printBottomTier( int num[], int numSize )
{
	// �����ؾ� �� �Լ�
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // �� ���ڸ� ����ϱ� ���� ù ��° �� ���
		{
			case 1:
			case 4:
			case 7:
			case 9:
				printf( "   " );
				break;
			default :
				printf( " - " );
				break;
		}
		printf( " " ); // ���� ������ ���� (�� ĭ�� space�� �̿�)
	}
	printf("\n");
}