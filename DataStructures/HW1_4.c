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
// phead: ����Ʈ�� ��� �������� ������
// p : ���� ���, node : ���Ե� ��� 
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
// phead: ����Ʈ�� ��� �������� ������
// p : ���� ���, node : ���Ե� ��� 
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
void display(ListNode *head) // ���󰡺��� � ���? Ʋ��!
{
	ListNode *p;
	if( head == NULL ) return;

	p = head;
	do {
		printf("%d->", p->data);
		p = p->link;
    } while(p != head);
}
void display2(ListNode *head)  // ù��° ����� ������ ����� ��µǰ�
{ 
	ListNode *p, *front;
    if( head == NULL ) { printf("����Ʈ��"); return; }
     
	front = head->link;
    p = front;
	do {
	     printf("%d->", p->data);
	     p = p->link;
    } while(p != front);
    printf("����Ʈ��");
}
void delete_first(ListNode **phead) 
{
     ListNode *temp;
     if (*phead == NULL) {
          printf("����Ʈ�� ��� ������ ����\n");
          return;
     } 
     else if (*phead == (*phead)->link) {  // �� �ϳ��� ��尡 �������� 
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
//�߰�
void delete_last(ListNode **phead)
{
	ListNode *temp;
     if (*phead == NULL) {
          printf("����Ʈ�� ��� ������ ����\n");
          return;
     } 
     else if (*phead == (*phead)->link) {  // �� �ϳ��� ��尡 �������� 
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
int main(void) // ���� ���� ����Ʈ �׽�Ʈ ���α׷�
{
	ListNode *list1=NULL;

	// list1 = 10->20->30
	insert_first(&list1, create_node(30)); 
	insert_first(&list1, create_node(20));
	insert_first(&list1,  create_node(10));
	display2(list1);

     printf("\n-���� �κ�-\n"); display2(list1); printf("\n"); //10->20->30->����Ʈ������ ���
     printf("���̴� %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //20->30->����Ʈ��
     printf("���̴� %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //30->����Ʈ��
     printf("���̴� %d\n\n", getLength(list1));

     delete_first(&list1); display2(list1); printf("\n"); //����Ʈ��
     printf("���̴� %d\n\n", getLength(list1));

     delete_first(&list1); //"����Ʈ�� ��� ���� ����"�� ���

	 //list1 = 10->20->30
	 insert_last(&list1, create_node(10));
	 insert_last(&list1, create_node(20));
	 insert_last(&list1, create_node(30));
	 display2(list1); printf("\n");

	 delete_last(&list1); display2(list1); printf("\n"); // 10->20->����Ʈ��
	 delete_last(&list1); display2(list1); printf("\n"); // 10->����Ʈ��
	 delete_last(&list1); display2(list1); printf("\n"); // ����Ʈ��
	 delete_last(&list1);  // "����Ʈ�� ��� ���� ����"�� ���
}