#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_PER_LINE 100

// 1)
typedef struct { 
	char line[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;   
} ListNode; 

void display_te(ListNode *head) // text editor�� ���� ���� // 2)
{
	ListNode *p=head;
	int lineCount = 0;
    	printf("----------text edited---------\n");
	while( p != NULL ){
		printf("(%d) %s", ++lineCount, p->data.line);
		p = p->link;
    }
}
// ������ �Լ��� ���Ǹ� �״�� ���⿡

char askChoice(void)
{
	char choice;
	printf("------------------------------\n");
	printf("a: �ؽ�Ʈ ���� ���� �߰�\n");
	printf("i: ���� ��ȣ�� ���� �߰�\n");
	printf("d: ���� ��ȣ�� ���� ����\n");
	printf("v: ���� ��ȣ�� �ش� ���� ���\n");
	printf("p: ��ü �ؽ�Ʈ ���\n");
	printf("q: ��\n");

	printf("�޴� ����:"); 
	scanf("%c", &choice);
	return choice;
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
element get_entry(ListNode *head, int pos)
{
	int i;
	ListNode *p = head;
	for (i = 0; i < pos; i++)
		p = p->link;

	return (p->data);
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
void insert_node_at(ListNode **list, int position, ListNode *new_node)
{
	ListNode *p;
	int i = 0;
	if (position < 0 || position > get_length(*list))
	{
		printf("���� ��ġ ����\n");
		return;
	}
	if (*list == NULL)
	{
		new_node->link = NULL;
		*list = new_node;
	}
	else if (position == 0)
	{
		new_node->link = *list;
		*list = new_node;
	}
	else 
	{
		p = *list;
		for (i = 0; i < position - 1; i++)
			p = p->link;
		new_node->link = p->link;
		p->link = new_node;
	}
}
 void remove_node_at(ListNode **list, int position)
{
	int i = 0;
	ListNode *p = *list, *prep;
	if (position < 0 || position >= get_length(*list))
	{
		printf("���� ��ġ ����\n");
		return;
	}
	if (*list == NULL)
	{
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	}
	else if (position == 0)
	{
		p = *list;
		*list = (*list)->link;
		free(p);
	}
	else 
	{
		p = *list;
		for (i = 0; i < position - 1; i++)
		{
			p = p->link;
		}
		prep = p->link;
		p->link = p->link->link;
		free(prep);
	}
}
int main(void) // 3)
{
	ListNode *list = NULL;
	char choice;
	int lineNb;
	element newElement;

     while ((choice = askChoice()) != 'q') {
          switch (choice) {
               case 'a':
					printf("�ؽ�Ʈ ���� ������ ����: ");
					fflush(stdin);
					fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				 
					insert_node_last(&list, create_node(newElement));
					display_te(list);
                   	break;
				case 'i':
					printf("������ ���� ��ȣ: ");
					scanf("%d", &lineNb);
				   
					printf("������ ����: ");
					fflush(stdin);
					fgets(newElement.line, MAX_CHAR_PER_LINE, stdin); 
				 
					insert_node_at(&list, lineNb - 1,  create_node(newElement));
					display_te(list);
                    break;
               case 'd':
					printf("������ ���� ��ȣ: ");
					scanf("%d", &lineNb);
				   
					remove_node_at(&list, lineNb - 1);
					display_te(list);
                   	break;
				case 'v':
					printf("����� ���� ��ȣ: ");
					scanf("%d", &lineNb);

					newElement = get_entry(list, lineNb - 1);
					printf("(%d) %s", lineNb, newElement.line);
					break;
				case 'p':
					display_te(list);
          }
          fflush(stdin);
    }
}