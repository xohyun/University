#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   	
} ListNode; 

// 노드를 동적으로 생성하는 프로그램
ListNode *create_node(element data)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode)); 
	if( new_node == NULL ) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = NULL;
	return(new_node);
}
// phead: 리스트의 헤드 포인터의 포인터
// p : 선행 노드, node : 삽입될 노드 
void insert_first(ListNode **HEAD,	ListNode *node) 
{
	if( *HEAD == NULL ){
		*HEAD = node;
		node->link = node;
	}
	else {
		node->link = (*HEAD)->link;
		(*HEAD)->link = node     ;
	}
}
// phead: 리스트의 헤드 포인터의 포인터
// p : 선행 노드, node : 삽입될 노드 
void insert_last(ListNode **HEAD, ListNode *node) 
{
	if( *HEAD == NULL ){
		*HEAD = node;
		node->link = node;
	}
	else {
		node->link = (*HEAD)->link;
		(*HEAD)->link = node;
		*HEAD = node;
	}
}
void display(ListNode *head) // 따라가보면 어떤 출력? 틀림!
{
	ListNode *p;
	if( head == NULL ) return;

	p = head;
	do {
		printf("%d->", p->data);
		p = p->link;
    } while(p != head);
}
void display2(ListNode *head)  // 첫번째 노드의 값부터 제대로 출력되게
{ 
	ListNode *p, *front;
    if( head == NULL ) { printf("리스트끝"); return; }
     
	front = head->link;
    p = front;
	do {
	     printf("%d->", p->data);
	     p = p->link;
    } while(p != front);
    printf("리스트끝");
}
void delete_first(ListNode **phead) 
{
     ListNode *temp;
     if (*phead == NULL) {
          printf("리스트가 비어 삭제를 못함\n");
          return;
     } 
     else if (*phead == (*phead)->link) {  // 즉 하나의 노드가 남았을때 
          temp = *phead;
          *phead = NULL;
          free(temp);
     }
    else {
          temp = (*phead)->link;
          (*phead)->link = temp->link;
          free(temp);
     }
}   
int getLength(ListNode *head) 
{ 
     int length = 0;
     if (head == NULL)
          return 0;
     else {
          ListNode *p = head->link;
          length++;     
          while (p != head){
               p = p->link;
               length++;
          }
     }
     return length;
}
//추가
void delete_last(ListNode **phead)
{
	ListNode *temp;
     if (*phead == NULL) {
          printf("리스트가 비어 삭제를 못함\n");
          return;
     } 
     else if (*phead == (*phead)->link) {  // 즉 하나의 노드가 남았을때 
          temp = *phead;
          *phead = NULL;
          free(temp);
     }
    else {
          temp = (*phead)->link;
		  do {
			  temp = temp->link;
		  }while(temp->link != *phead);
		
		  temp->link = (*phead)->link;
		  *phead = temp;
		  temp = NULL;
         // (*phead)->link = temp->link;
         free(temp);	 
	}
}
int main(void) // 원형 연결 리스트 테스트 프로그램
{
	ListNode *list1=NULL;

	// list1 = 10->20->30
	insert_first(&list1, create_node(30)); 
	insert_first(&list1, create_node(20));
	insert_first(&list1,  create_node(10));
	display2(list1);

     printf("\n-숙제 부분-\n"); display2(list1); printf("\n"); //10->20->30->리스트끝으로 출력
     printf("길이는 %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //20->30->리스트끝
     printf("길이는 %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //30->리스트끝
     printf("길이는 %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //리스트끝
     printf("길이는 %d\n\n", getLength(list1));

     delete_first(&list1); //"리스트가 비어 삭제 못함"을 출력

	 //list1 = 10->20->30
	 insert_last(&list1, create_node(10));
	 insert_last(&list1, create_node(20));
	 insert_last(&list1, create_node(30));
	 display2(list1); printf("\n");

	 delete_last(&list1); display2(list1); printf("\n"); // 10->20->리스트끝
	 delete_last(&list1); display2(list1); printf("\n"); // 10->리스트끝
	 delete_last(&list1); display2(list1); printf("\n"); // 리스트끝
	 delete_last(&list1);  // "리스트가 비어 삭제 못함"을 출력
}