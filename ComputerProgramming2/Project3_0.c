//Project(���� ���� #1) 20170988 ��ǻ���а� 17�й� �Ѽ���
#define MAX_VIDEO 100
#define MAX_CHAR 100 // ���ڿ��� max ����

#include <stdio.h>
#include <string.h>

struct VideoInfo { // ��� ����: ���� �����ϰ� �ִ� Video ���� ����
	char title[MAX_CHAR] ;
	int qty ; // ����
};

int main(void)
{
	int videoCount = 5;
	struct VideoInfo videoList[MAX_VIDEO] = {{"BeforeSunrise", 1}, {"BeforeSunset", 3}, {"BeforeMidnight", 0}, {"Casablanca", 7}, {"EdgeOfTomorrow", 9}}; // ���� ����ó�� �ʱ�ȭ

	char title[MAX_CHAR];
	int qty;

	// �ʿ��� ���� �߰�
	int i;
	int choice;
	int have_qty = 0;

	printf("1(All Video ���), 2(����), 3(�˻�), 4(����): ");
	scanf("%d", &choice);
	while (choice != 4) {
		switch(choice) {
			case 1: // ���� Video���� ���
				printf("Video ����\t ����\n");
				printf("-----------------------\n");
				// ����
				for (i = 0; i < videoCount; i++)
					printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
				break;
			case 2: // Video ����
				printf("Enter video ����: ");
				scanf("%s", title);
				printf("Enter video ����: ");
				scanf("%d", &qty);
				// ����
				strcpy(videoList[videoCount].title, title);
				videoList[videoCount].qty = qty;
				videoCount++;
				break;
			case 3: // title �� Video ã��
				printf("Enter video ����: ");
				scanf("%s", title);
				//����
				for (i = 0; i < videoCount; i++)
					if (strcmp(title, videoList[i].title) == 0)
					{
						have_qty = 1;
						break;
					}
				if (have_qty)
				{
					if (videoList[i].qty != 0)
						printf("�뿩 �����մϴ�.\n");
					else
						printf("�� �뿩���Դϴ�.\n");
				}
				else
					printf("�׷� ������ �����ϴ�.\n");
				break;
		}
		
		printf("1(All Video ���), 2(����), 3(�˻�), 4(����): ");
		scanf("%d", &choice);
	}
}