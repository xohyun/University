#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   
} ListNode; 

// phead: 리스트의 헤드 포인터의 포인터, new_node : 삽입될 노드 
void insert_node_first(ListNode **pHEAD, ListNode *new_node) 
{
	if( *pHEAD == NULL ){	// 공백리스트인 경우
		new_node->link = NULL; 
		*pHEAD = new_node;
	}
	else {
		new_node->link = *pHEAD;
		*pHEAD = new_node;     
	}
}
void insert_node_last(ListNode **pHEAD, ListNode *new_node) 
{
	ListNode *p;
	if( *pHEAD == NULL ){	// 공백리스트인 경우
		new_node->link = NULL; 
		*pHEAD = new_node; 
	}
	else {
		p = *pHEAD;            
		while (p->link != NULL)
			p = p->link;  
		p->link = new_node  ;
	}
}
void remove_node_first(ListNode **pHEAD) 
{
     ListNode *p;

     if (*pHEAD == NULL)
          printf("리스트가 비어 있음\n");
     else {
          p = *pHEAD;                      
          *pHEAD = (*pHEAD)->link;           
		free(p);
     } 
}
void remove_node(ListNode *HEAD, element item) {
     ListNode *p, *prevp;
     
     if (HEAD == NULL)
          printf("리스트는 비어있습니다.\n");
     else if ((HEAD)->data == item) { // 삭제해야하는 노드가 첫번째 노드이면
          p = HEAD           ;
          HEAD = (HEAD)->link;
          free(p);
     }
     else {
          p = HEAD;
          do { 
               prevp = p;
               p = p->link;
          } while (p != NULL && p->data != item);  // item을 찾을때까지 전진, p 뒤에 prevp
          if (p != NULL) { // item 발견!
               prevp->link = p->link                ; // 삭제하려는 노드의 앞뒤를 연결
               free(p);
          }
          else
               printf("%d은 리스트에 없음\n", item);
     }
}

void display(ListNode *head)
{
	ListNode *p=head;
	while( p != NULL ){
		printf("%d->", p->data);
		p = p->link;
    	}
	printf("\n");
}

ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while( p != NULL ){
		if( p->data == x ) return p;              // 탐색 성공
		p = p->link;
	}
	return p;  // 탐색 실패일 경우 NULL 반환
}

ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if( head1 == NULL ) return head2;
	else if( head2 == NULL ) return head1;
	else {
		p = head1;             
		while( p->link != NULL ) 
			p = p->link;    
		p->link = head2;        
		return head1;           
	}
}

ListNode *reverse(ListNode *head)
{
   // 순회 포인터로 p, q, r을 사용
   ListNode *p, *q, *r;
   p = head;         // p는 역순으로 만들 리스트
   q = NULL;         // q는 역순으로 만들 노드
   while (p != NULL){
       r = q;            // r은 역순으로 된 리스트.    r은 q, q는 p를 차례로 따라간다.
       q = p;
       p = p->link;
       q->link =r;      // q의 링크 방향을 바꾼다.
    }
    return q; 	// q는 역순으로 된 리스트의 헤드 포인터
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

int is_in_list(ListNode *head, element item)
{
	while (head != NULL) {
		if (head->data == item)
			return TRUE;
		head = head->link;
	}
	return FALSE;
}
int get_length(ListNode *head)
{
	int num = 0;
	while (head != NULL) {
		head = head->link;
		num++;
	}
	return num;
}
int get_total(ListNode *head)
{
	int sum = 0;
	while (head != NULL) {
		sum += head->data;
		head = head->link;
	}
	return sum;
}
element get_entry(ListNode *head, int pos)
{
	return (head[pos].data);
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	
	insert_node_first(&list1, create_node(10));
	insert_node_first(&list1, create_node(20));
	insert_node_first(&list1, create_node(30));
	display(list1);

	remove_node_first(&list1);
	display(list1);
	
	insert_node_last(&list2, create_node(11));
	insert_node_last(&list2, create_node(22));
	insert_node_last(&list2, create_node(33));
	insert_node_last(&list2, create_node(44));
	display(list2);

	remove_node(list2, 33);
	display(list2);

	list3 = reverse(list2);
	display(list3);

	list1 = concat(list1, list3);
	display(list1);
}