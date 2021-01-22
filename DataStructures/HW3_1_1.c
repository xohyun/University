#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3

typedef struct{
	char name[81];
	char gender;
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error (char *message)
{
	fprintf(stderr,"%s\n", message);
	exit(1);
}
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
void enqueue(QueueType *q, element item, int n)
{
	if(is_full(q))
	{
		//error("ť�� ��ȭ�����Դϴ�.");
		printf("����ڰ� ��á���� ���ȸ�� �̿�\n");
		return;
	}
	
	if (n == 0)
		printf("��ٷ��ֽʽÿ�.\n");

	q->rear = ((q->rear + 1) % MAX_QUEUE_SIZE);
	strcpy(q->queue[q->rear].name, item.name);
	q->queue[q->rear].gender = item.gender;
}
element dequeue(QueueType *q)
{
	if(is_empty(q))
		error("ť�� ��������Դϴ�.");
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}
element peek(QueueType *q)
{
	if(is_empty(q))
		error("ť�� ��������Դϴ�.");
	
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count (QueueType *q)
{
	if(q->front <= q->rear)
		return (q->rear - q->front);
	else
		return MAX_QUEUE_SIZE - q->front + q->rear;
}

void print_queue (QueueType *q)
{
	int i = 0, n;
	printf("����� %d��: ", get_count(q));
	
	n = (q->front + 1) % MAX_QUEUE_SIZE;
	while(i < get_count(q))
	{
		printf("%s ", q->queue[n].name);
		n = (n + 1) % MAX_QUEUE_SIZE;
		i++;
	}
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

			if (newPerson.gender == 'm'){
				if(get_count(&womanQ) == 0)
					printf("���� ����ڰ� �����ϴ�.");
				enqueue(&manQ, newPerson, get_count(&womanQ));
			}
			else {
				if(get_count(&manQ) == 0)
					printf("���� ����ڰ� �����ϴ�.");
				enqueue(&womanQ, newPerson, get_count(&manQ));
			}
			
			if(get_count(&manQ) != 0 && get_count(&womanQ) != 0)
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
