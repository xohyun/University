#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   
} ListNode; 

void display(ListNode *head)
{
	ListNode *p=head;
	while( p != NULL ){
		printf("%d->", p->data);
		p = p->link;
    	}
	printf("\n");
}

ListNode *create_node(element data) {
     ListNode *new_node;

     new_node = (ListNode *)malloc(sizeof(ListNode));
     if (new_node == NULL) {
	     printf("�޸� �ҵ� ����.\n"); exit(1);
     }
     new_node->data = data;
     new_node->link = NULL;
     
     return(new_node); 
}

void remove_even_pos(ListNode **phead)
{
	// ���� �κ� �߰�
   /* ListNode *p;
    p = (*phead)->link;
    
    if (*phead == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
    }
    else {
        while(p != NULL && p->link != NULL && p->link->link != NULL) {
            p->link = p->link->link;
            p = p->link;
        }
        
    }
	p->link = NULL;
	p = (*phead)->link;
	(*phead) = p;*/

	ListNode *p = *phead;
	if(*phead == NULL)
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	
	else {
		p = p->link;
		*phead = p;
		while(p!=NULL && p->link!= NULL) {
			p->link = p->link->link;
			p = p->link;
		}
	}
}

// phead: ����Ʈ�� ��� �������� ������
// new_node : ���Ե� ��� 
void insert_node_last(ListNode **phead, ListNode *new_node) 
{
	ListNode *p;
	if( *phead == NULL ){	// ���鸮��Ʈ�� ���
		new_node->link = NULL; 
		*phead = new_node; 
	}
	else {
		p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
}

int main(void)
{
	ListNode *list1 = NULL, *removed;
	ListNode *subList1 = NULL, *subList2 = NULL;
	int n;

	scanf("%d", &n);
	while (n != -1) {
       		insert_node_last(&list1, create_node(n));
		scanf("%d", &n);
	}

	display(list1); 

	remove_even_pos(&list1);
	display(list1);
}