//디지털시계 20170988 컴퓨터학과 17학번 한소현
#include <stdio.h>
#define MAX_NUMBERS 10
void printTopTier( int num[], int numSize ); // 첫 번째 줄을 출력하는 함수
void printSecondTier( int num[], int numSize ); // 두 번째 줄을 출력하는 함수
void printMiddleTier( int num[], int numSize ); //세 번째 줄을 출력하는 함수
void printFourthTier( int num[], int numSize ); // 네 번째 줄을 출력하는 함수
void printBottomTier( int num[], int numSize ); // 첫 번째 줄을 출력하는 함수
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
		switch( num[i] ) // 각 숫자를 출력하기 위한 첫 번째 줄 출력
		{
			case 1:
			case 4:
				printf( "   " );
				break;
			default :
				printf( " - " );
				break;
		}
		printf( " " ); // 숫자 사이의 공백 (두 칸의 space를 이용)
	}
	printf("\n");
}
void printSecondTier( int num[], int numSize )
{
	// 구현해야 할 함수
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // 각 숫자를 출력하기 위한 첫 번째 줄 출력
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
		printf( " " ); // 숫자 사이의 공백 (두 칸의 space를 이용)
	}
	printf("\n");

}
void printMiddleTier( int num[], int numSize )
{
	// 구현해야 할 함수
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // 각 숫자를 출력하기 위한 첫 번째 줄 출력
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
		printf( " " ); // 숫자 사이의 공백 (두 칸의 space를 이용)
	}
	printf("\n");
}
void printFourthTier( int num[], int numSize )
{
	// 구현해야 할 함수
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // 각 숫자를 출력하기 위한 첫 번째 줄 출력
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
		printf( " " ); // 숫자 사이의 공백 (두 칸의 space를 이용)
	}
	printf("\n");
}
void printBottomTier( int num[], int numSize )
{
	// 구현해야 할 함수
	int i = 0;
	for( i = 0 ; i < numSize ; i++ )
	{
		switch( num[i] ) // 각 숫자를 출력하기 위한 첫 번째 줄 출력
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
		printf( " " ); // 숫자 사이의 공백 (두 칸의 space를 이용)
	}
	printf("\n");
}