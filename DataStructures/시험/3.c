#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

// 이중 연결 리스트를 초기화
void init(DlistNode *phead) 
{
	phead->llink = phead;
	phead->rlink = phead;
}


void display2(DlistNode *phead) 
{
	DlistNode *p;
	for(p=phead->rlink; p != phead; p = p->rlink){
		printf("%d ", p->data);
	}
	printf("|\n");
}
// 노드 new_node를 노드 before의 오른쪽에 삽입한다.
void dinsert_node(DlistNode *before,	DlistNode *new_node) 
{ 
	new_node->llink = before; 
	new_node->rlink = before->rlink; 
	before->rlink->llink = new_node; 
	before->rlink = new_node; 
} 

DlistNode * dcreate_node(element data) // 교재에는 없음.
{
	DlistNode *temp;
	temp = (DlistNode *)malloc(sizeof(DlistNode));
	temp->llink = NULL;
	temp->data = data;
	temp->rlink = NULL;
	return temp;
}

void remove_even_pos(DlistNode *phead_node)
{
	// 함수 정의 추가
	DlistNode *p = phead_node;
	if(phead_node == NULL)
		printf("리스트는 비어있습니다.\n");
	
	else {
		p = p->rlink;
		
		while(p->rlink != phead_node && p != phead_node){
			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;
			p = p->rlink->rlink;	
			if (p->rlink == phead_node)
			{
				p->llink->rlink = p->rlink;
				p->rlink->llink = p->llink;
			}
		}

		/*
		p = p->link;
		*phead = p;
		while(p!=NULL && p->link!= NULL) {
			p->link = p->link->link;
			p = p->link;
		}
		*/

	}

}


// 이중 연결 리스트 테스트 프로그램
int main(void)// 프로그램 4.18을 조금 변경
{
	DlistNode head_node;
	int n;
	init(&head_node);
    
	scanf("%d", &n);
	while (n != -1) {
		dinsert_node(head_node.llink, dcreate_node(n));
		scanf("%d", &n);
	}

	//display2(&head_node);
	
	// 여기에 remove_even_pos 함수 호출 부분 추가
	remove_even_pos(&head_node);
	
	display2(&head_node);
}