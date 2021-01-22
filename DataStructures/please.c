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

	ListNode *p = head;

	int lineCount = 0;

    printf("----------text edited---------\n");

	while(p != NULL)

	{

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

int get_length(ListNode *head)//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ

{

	int length = 0;

	if (head == NULL)

		return 0;

	else {

		ListNode *p = head->link;

		do {

			length++;

			p = p->link;

		}while (p != head->link);

	}

	return length;

}

element get_entry(ListNode *head, int pos)//pos��ġ(0�� ù ��° ���)�� �ִ� ����� data�� ��ȯ

{

	ListNode *p = head;

	int i;

	if (pos > get_length(head))

	{

		printf("��ġ ����\n");

		exit(1);

	}

	for (i = 0; i < pos; i++)

		p = p->link;

	return p->data;

}

void insert_node_last(ListNode **phead, ListNode *new_node) 

{

	ListNode *p;

	if(*phead == NULL ){	// ���鸮��Ʈ�� ���

		new_node->link = NULL; 

		*phead = new_node; 

	}

	else {

		p = *phead;            

		while (p->link != NULL)

			p = p->link;  

		p->link = new_node  ;

	}

}

ListNode *create_node(element data) {

     ListNode *new_node;

 

     new_node = (ListNode *)malloc(sizeof(ListNode));

     if (new_node == NULL) {

	     printf("�޸� �ҵ� ����.\n");

		 exit(1);

     }                                         

     new_node->data = data;                    

     new_node->link = NULL;                     

                                                 

     return(new_node);                              

}

void remove_node_at(ListNode **phead, int pos)

{

	ListNode *p, *prevp;

	int i;

 

	if (pos < 0 || pos >= get_length(*phead))

	{

		printf("���� ��ġ ����\n");

		return;

	}

	if (*phead == NULL)

		printf("����Ʈ�� ����ֽ��ϴ�\n");

	else if (pos == 0)

	{

		p = *phead;

		*phead = (*phead)->link;

		free(p);

	}

	else

	{

		p = *phead;

		for (i = 0; i < pos - 1; i++)

			p = p->link;

		prevp = p->link;

		p->link = p->link->link;

		free(prevp);

	}

}

void insert_node_at(ListNode **phead, int pos, ListNode *new_node)

{

	ListNode *p;

	int i;

 

	if (pos < 0 || pos > get_length(*phead))

	{

		printf("���� ��ġ ����\n");

		return;

	}

	if (*phead == NULL)

	{

		new_node->link = NULL;

		*phead = new_node;

	}

	else if (pos == 0)

	{

		new_node->link = *phead;

		*phead = new_node;

	}

	else

	{

		p = *phead;

		for (i = 0; i < pos - 1; i++)

			p = p->link;

		new_node->link = p->link;

		p->link = new_node;

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

				 

				 insert_node_at(&list, lineNb - 1, create_node(newElement));

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