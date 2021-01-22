#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   
} ListNode; 

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

// phead : ��� �����Ϳ� ���� ������ 
void remove_node_first(ListNode **phead) 
{
     ListNode *p;

     if (*phead == NULL)
          printf("����Ʈ�� ��� ����\n");
     else {
          p = *phead;
          *phead = (*phead)->link;
     } 
     free(p);		
}
void display(ListNode *head)
{
	ListNode *p=head;
	while( p != NULL ){
		printf("%d->", p->data);
		p = p->link;
    	}
	printf("|\n");
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

void printCheck(ListNode *list1, ListNode *list2)
{
	display(list1); // ù��° ��尡 ������ list1�� ���
	display(list2); // ���� list2�� ���
}
ListNode *copyList(ListNode *node)
{
	// ���⿡ �Լ� ����
	ListNode *node2;
	node2 = (ListNode *)malloc(sizeof(ListNode));

	if (node == NULL)
		return NULL;

	node2->data = node->data;

	node2->link = copyList(node->link);


	return node2;
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL;
	int n;

	scanf("%d", &n);
	while (n != -1) {
		insert_node_last(&list1, create_node(n));	
		scanf("%d", &n);
	}
	list2 = copyList(list1);
	remove_node_first(&list1); 
	printCheck(list1, list2);
}