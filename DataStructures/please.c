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

void display_te(ListNode *head) // text editor를 위해 변경 // 2)

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

// 나머지 함수들 정의를 그대로 여기에

char askChoice(void)

{

	char choice;

	printf("------------------------------\n");

	printf("a: 텍스트 끝에 라인 추가\n");

	printf("i: 라인 번호로 라인 추가\n");

	printf("d: 라인 번호로 라인 삭제\n");

	printf("v: 라인 번호로 해당 라인 출력\n");

	printf("p: 전체 텍스트 출력\n");

	printf("q: 끝\n");

 

	printf("메뉴 선택:"); 

	scanf("%c", &choice);

	return choice;

}

int get_length(ListNode *head)//단순 연결 리스트에 존재하는 노드의 수를 반환

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

element get_entry(ListNode *head, int pos)//pos위치(0이 첫 번째 노드)에 있는 노드의 data를 반환

{

	ListNode *p = head;

	int i;

	if (pos > get_length(head))

	{

		printf("위치 오류\n");

		exit(1);

	}

	for (i = 0; i < pos; i++)

		p = p->link;

	return p->data;

}

void insert_node_last(ListNode **phead, ListNode *new_node) 

{

	ListNode *p;

	if(*phead == NULL ){	// 공백리스트인 경우

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

	     printf("메모리 할딩 에러.\n");

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

		printf("삭제 위치 오류\n");

		return;

	}

	if (*phead == NULL)

		printf("리스트는 비어있습니다\n");

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

		printf("삽입 위치 오류\n");

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

				 printf("텍스트 끝에 삽입할 라인: ");

				 fflush(stdin);

				 fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

				 

				 insert_node_last(&list, create_node(newElement));

				 display_te(list);

                 break;

			 case 'i':

				 printf("삽입할 라인 번호: ");

				 scanf("%d", &lineNb);

				   

				 printf("삽입할 라인: ");

				 fflush(stdin);

				 fgets(newElement.line, MAX_CHAR_PER_LINE, stdin); 

				 

				 insert_node_at(&list, lineNb - 1, create_node(newElement));

				 display_te(list);

                 break;

             case 'd':

				 printf("삭제할 라인 번호: ");

				 scanf("%d", &lineNb);

				   

				 remove_node_at(&list, lineNb - 1);

				 display_te(list);

                 break;

			 case 'v':

			     printf("출력할 라인 번호: ");

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