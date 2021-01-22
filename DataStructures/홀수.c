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
	     printf("메모리 할딩 에러.\n"); exit(1);
     }
     new_node->data = data;
     new_node->link = NULL;
     
     return(new_node); 
}

void remove_even_pos(ListNode **phead)
{
	// 정의 부분 추가
   /* ListNode *p;
    p = (*phead)->link;
    
    if (*phead == NULL) {
        printf("리스트는 비어있습니다.\n");
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
		printf("리스트는 비어있습니다.\n");
	
	else {
		p = p->link;
		*phead = p;
		while(p!=NULL && p->link!= NULL) {
			p->link = p->link->link;
			p = p->link;
		}
	}
}

// phead: 리스트의 헤드 포인터의 포인터
// new_node : 삽입될 노드 
void insert_node_last(ListNode **phead, ListNode *new_node) 
{
	ListNode *p;
	if( *phead == NULL ){	// 공백리스트인 경우
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