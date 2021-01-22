#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   	
} ListNode; 

// ��带 �������� �����ϴ� ���α׷�
ListNode *create_node(element data)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode)); 
	if( new_node == NULL ) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = NULL;
	return(new_node);
}
void insert_last(ListNode **phead, ListNode *node) 
{
	if( *phead == NULL ){
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

void display2(ListNode *head)
{
     ListNode *p, *front;
     if( head == NULL ) { printf("|"); return; }
     
	front = head->link;
     p = front;
	do {
	     printf("%d->", p->data);
	     p = p->link;
     } while(p != front);
     printf("|\n");
}

void increaseOneTwoEtc(ListNode *head)
{
	int count = 1;
	ListNode *p = head;
	// �Լ��� ���� �ڵ� �߰�
	p = p->link;
	do
	{
		p->data += count;
		count++;
		
		p = p->link;
	}while(p != head->link);
}      
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *list = NULL;
	int num;

	scanf("%d", &num);
	while (num != -1) {
		insert_last(&list, create_node(num));	
		scanf("%d", &num);
	}
	//display2(list); 
	increaseOneTwoEtc(list);
	display2(list); 
}