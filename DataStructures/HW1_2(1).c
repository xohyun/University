#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   
} ListNode; 

// phead: ����Ʈ�� ��� �������� ������, new_node : ���Ե� ��� 
void insert_node_first(ListNode **pHEAD, ListNode *new_node) 
{
	if( *pHEAD == NULL ){	// ���鸮��Ʈ�� ���
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
	if( *pHEAD == NULL ){	// ���鸮��Ʈ�� ���
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
          printf("����Ʈ�� ��� ����\n");
     else {
          p = *pHEAD;                      
          *pHEAD = (*pHEAD)->link;           
		free(p);
     } 
}
void remove_node(ListNode *HEAD, element item) {
     ListNode *p, *prevp;
     
     if (HEAD == NULL)
          printf("����Ʈ�� ����ֽ��ϴ�.\n");
     else if ((HEAD)->data == item) { // �����ؾ��ϴ� ��尡 ù��° ����̸�
          p = HEAD           ;
          HEAD = (HEAD)->link;
          free(p);
     }
     else {
          p = HEAD;
          do { 
               prevp = p;
               p = p->link;
          } while (p != NULL && p->data != item);  // item�� ã�������� ����, p �ڿ� prevp
          if (p != NULL) { // item �߰�!
               prevp->link = p->link                ; // �����Ϸ��� ����� �յڸ� ����
               free(p);
          }
          else
               printf("%d�� ����Ʈ�� ����\n", item);
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
		if( p->data == x ) return p;              // Ž�� ����
		p = p->link;
	}
	return p;  // Ž�� ������ ��� NULL ��ȯ
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
   // ��ȸ �����ͷ� p, q, r�� ���
   ListNode *p, *q, *r;
   p = head;         // p�� �������� ���� ����Ʈ
   q = NULL;         // q�� �������� ���� ���
   while (p != NULL){
       r = q;            // r�� �������� �� ����Ʈ.    r�� q, q�� p�� ���ʷ� ���󰣴�.
       q = p;
       p = p->link;
       q->link =r;      // q�� ��ũ ������ �ٲ۴�.
    }
    return q; 	// q�� �������� �� ����Ʈ�� ��� ������
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