#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
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
// ��� new_node�� ��� before�� �����ʿ� �����Ѵ�.
void dinsert_node(DlistNode *before,	DlistNode *new_node) 
{ 
	new_node->llink = before; 
	new_node->rlink = before->rlink; 
	before->rlink->llink = new_node; 
	before->rlink = new_node; 
} 

DlistNode * dcreate_node(element data) // ���翡�� ����.
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
	// �Լ� ���� �߰�
	DlistNode *p = phead_node;
	if(phead_node == NULL)
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	
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


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)// ���α׷� 4.18�� ���� ����
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
	
	// ���⿡ remove_even_pos �Լ� ȣ�� �κ� �߰�
	remove_even_pos(&head_node);
	
	display2(&head_node);
}