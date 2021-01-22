//Project(비디오 관리 #1) 20170988 컴퓨터학과 17학번 한소현
#define MAX_VIDEO 100
#define MAX_CHAR 100 // 문자열의 max 문자

#include <stdio.h>
#include <string.h>

struct VideoInfo { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR] ;
	int qty ; // 수량
};

int main(void)
{
	int videoCount = 5;
	struct VideoInfo videoList[MAX_VIDEO] = {{"BeforeSunrise", 1}, {"BeforeSunset", 3}, {"BeforeMidnight", 0}, {"Casablanca", 7}, {"EdgeOfTomorrow", 9}}; // 앞의 정보처럼 초기화

	char title[MAX_CHAR];
	int qty;

	// 필요한 변수 추가
	int i;
	int choice;
	int have_qty = 0;

	printf("1(All Video 출력), 2(구입), 3(검색), 4(종료): ");
	scanf("%d", &choice);
	while (choice != 4) {
		switch(choice) {
			case 1: // 보유 Video들을 출력
				printf("Video 제목\t 수량\n");
				printf("-----------------------\n");
				// 구현
				for (i = 0; i < videoCount; i++)
					printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
				break;
			case 2: // Video 구입
				printf("Enter video 제목: ");
				scanf("%s", title);
				printf("Enter video 수량: ");
				scanf("%d", &qty);
				// 구현
				strcpy(videoList[videoCount].title, title);
				videoList[videoCount].qty = qty;
				videoCount++;
				break;
			case 3: // title 로 Video 찾기
				printf("Enter video 제목: ");
				scanf("%s", title);
				//구현
				for (i = 0; i < videoCount; i++)
					if (strcmp(title, videoList[i].title) == 0)
					{
						have_qty = 1;
						break;
					}
				if (have_qty)
				{
					if (videoList[i].qty != 0)
						printf("대여 가능합니다.\n");
					else
						printf("다 대여중입니다.\n");
				}
				else
					printf("그런 비디오는 없습니다.\n");
				break;
		}
		
		printf("1(All Video 출력), 2(구입), 3(검색), 4(종료): ");
		scanf("%d", &choice);
	}
}