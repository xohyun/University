#define MAX_VIDEO 100
#define MAX_CUST 200 // max customer
#define MAX_CHAR 100 // 문자열의 max 문자
#include <stdio.h>
#include <string.h>

typedef struct { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR] ;
	int qty ; // 수량
} VideoInfo;

typedef struct { // 대출 대장: 대출해간 (고객 id와 video id)들을 저장
	int custId ; // 고객 id : 1, 2, 3
	char title[MAX_CHAR] ; // Video 제목
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount) 
{
	int i;
	
	printf("Video제목\t수량\n");
	printf("--------------------------\n");
	for(i = 0; i < videoCount; i++)
	{
		printf("%s\t%d\n", videoList->title, videoList->qty);
		videoList++;
	}
}

void purchaseVideo(VideoInfo videoList[], int *videoCountPtr, char *title, int qty) 
{
	int i;

	for(i = 0; i < *videoCountPtr; i++)
		videoList++;

	videoList->qty = qty;
	for(i = 0; *title != '\0'; i++)
		videoList->title[i] = *title++;
	(*videoCountPtr)++;
}

int searchVideoByTitle(VideoInfo *videoList, int videoCount, char *title) 
{
	int i, j;

	for(i = 0; i < videoCount; i++)
		if(strcmp(videoList++->title, title) == 0)//title은 포인터인데 문자열처럼 사용 가능?
			return i;
	return -1;
}

void rentVideo(VideoInfo *videoList, int videoCount, RentInfo rentList[], int *rentCount, char title[], int custId)
{
	int i;
	int count = searchVideoByTitle(videoList, videoCount, title);
	rentList->custId = custId;
	strcpy(rentList->title, title);
	rentList++;
	(*rentCount)++;
	
	for(i = 0; i < count; i++)
		videoList++;
	videoList->qty--;
}

void printAllRent(RentInfo *rentList, int rentCount) 
{
	int i;
	printf("고객id\tVideo제목\n----------------------------\n");
	for(i = 0; i < rentCount; i++)
	{
		printf("%d\t%s\n", rentList->custId, rentList->title);
		rentList++;
	}
}

int main(void)
{
	int videoCount = 5;
	VideoInfo videoList[MAX_VIDEO] = {{"BeforeSunrise", 1}, {"BeforeSunset", 3},{"BeforeMidnight", 5}, {"Casablanca", 7}, {"EdgeOfTomorrow", 9} };
	int rentCount = 0; // 현재 대출 건수는 0임
	RentInfo rentList[MAX_CUST];
	int choice;
	int indexSearched;
	char title[MAX_CHAR];
	int custId, qty;
	
	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);
	
	while (choice != 6) 
	{
		switch(choice) 
		{
			case 1: 
				printAllVideo(videoList, videoCount); 
				break;

			case 2:
				printf("Enter video 제목: ");
				scanf("%s", title);
				printf("Enter video 수량: ");
				scanf("%d", &qty);
				purchaseVideo(videoList, &videoCount, title, qty); 
				break;

			case 3:
				printf("Enter video 제목: ");
				scanf("%s", title);
				if ((indexSearched = searchVideoByTitle(videoList, videoCount, title)) == -1)
					printf("그런 비디오는 없습니다.\n");
				else if (videoList[indexSearched].qty == 0)
					printf("다 대여중입니다.\n");
				else
					printf("대여 가능합니다.\n"); 
				break;

			case 4:
				printf("Enter video 제목: ");
				scanf("%s", title);
				printf("Enter 고객 id: ");
				scanf("%d", &custId);
				rentVideo(videoList, videoCount, rentList, &rentCount, title, custId);
				break;

			case 5:
				printAllRent(rentList, rentCount); 
				break;
		}

	 printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	 scanf("%d", &choice);
	 }
} 