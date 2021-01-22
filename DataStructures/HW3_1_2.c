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
		error("�޸𸮸� �Ҵ��� �� �����ϴ�.\n");
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
		error("ť�� ��� �ֽ��ϴ�.\n");
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

	printf("����� %d��: ", get_count(q));
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

	printf("���� �ּ� ���α׷��Դϴ�.\n");
	while(1) {
		printf("i(nsert, ���Է�), c(check, ����� üũ), q(uit) : ");
		scanf("%c", &a);
		
		if(a == 'q') break;

		else if(a == 'i')
		{
			fflush(stdin);
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);

			fflush(stdin);

			printf("������ �Է�(m or f) : ");
			scanf("%c", &newPerson.gender);

			if (newPerson.gender == 'm')
				enqueue(&manQ, newPerson);
		
			else 
				enqueue(&womanQ, newPerson);
			
			
			if(get_count(&womanQ) == 0 || get_count(&manQ) == 0)
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");

			else if(get_count(&manQ) != 0 && get_count(&womanQ) != 0)
				printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
		}
		else
		{
			printf("���� "); print_queue(&manQ);
			printf("\n���� "); print_queue(&womanQ);
			printf("\n");
		}
		fflush(stdin);
	}
		
}