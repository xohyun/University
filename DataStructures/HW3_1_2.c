#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[81];
	char gender;
}element;

typedef struct QueueNode{
	element item;
	struct QueueNode *link;
}QueueNode;
typedef struct {
	QueueNode *front, *rear;
} QueueType;
void init(QueueType *q)
{
	q->front = q->rear = NULL;
}
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int is_empty(QueueType *q)
{
	return(q->front == NULL);
}
int is_full(QueueType *q)
{
	return 0;
}
void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if(temp == NULL){
		error("메모리를 할당할 수 없습니다.\n");
	}
	else {
		temp->item.gender = item.gender;
		strcpy(temp->item.name, item.name);
		temp->link = NULL;
		if (is_empty(q))
		{
			q->rear = temp;
			q->front = temp;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	element item;
	if (is_empty (q))
		error("큐가 비어 있습니다.\n");
	else 
	{
		item = temp->item;
		q->front = q->front->link;
		if(q->front == NULL) q->rear = NULL;
		free(temp);
		return item;
	}
}
int get_count (QueueType *q)
{
	int n = 0;
	QueueNode *temp = (QueueNode*) malloc(sizeof(QueueNode));
	temp = q->front;

	while(temp != NULL)
	{
		n++;
		temp = temp->link;
	}
	free(temp);
	return n;
}

void print_queue (QueueType *q)
{
	QueueNode *temp = (QueueNode*) malloc(sizeof(QueueNode));

	printf("대기자 %d명: ", get_count(q));
	temp = q->front;

	while(temp != NULL)
	{
		printf("%s ", temp->item.name);
		temp = temp->link;
	}
	free(temp);

}
int main(void)
{
	QueueType manQ, womanQ;
	element newPerson;
	char a;

	init(&manQ);
	init(&womanQ);

	printf("미팅 주선 프로그램입니다.\n");
	while(1) {
		printf("i(nsert, 고객입력), c(check, 대기자 체크), q(uit) : ");
		scanf("%c", &a);
		
		if(a == 'q') break;

		else if(a == 'i')
		{
			fflush(stdin);
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);

			fflush(stdin);

			printf("성별을 입력(m or f) : ");
			scanf("%c", &newPerson.gender);

			if (newPerson.gender == 'm')
				enqueue(&manQ, newPerson);
		
			else 
				enqueue(&womanQ, newPerson);
			
			
			if(get_count(&womanQ) == 0 || get_count(&manQ) == 0)
					printf("아직 대상자가 없습니다. 기다려주십시오.\n");

			else if(get_count(&manQ) != 0 && get_count(&womanQ) != 0)
				printf("커플이 탄생했습니다! %s와 %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
		}
		else
		{
			printf("남성 "); print_queue(&manQ);
			printf("\n여성 "); print_queue(&womanQ);
			printf("\n");
		}
		fflush(stdin);
	}
		
}