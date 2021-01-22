#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20	
#define MAX_STRING 100

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
} element;

typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void insert_node(TreeNode **root, element key)
{
	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;
	

	while(t != NULL) {
		if (t->data.id == key.id) return;
		p = t;

		if (t->data.id > key.id)
			t = t->left;
		else
			t = t->right;
	}
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if(n == NULL) return;

	n->data.id = key.id;
	strcpy(n->data.name, key.name);
	strcpy(n->data.tel, key.tel);
	strcpy(n->data.dept, key.dept);

	n->left = NULL;
	n->right = NULL;
	
	if (p != NULL){
		if (key.id < p->data.id) p->left = n;
		else					p->right = n;
	}
	else
		*root = n;
}


void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;


	while(t != NULL && t->data.id != key) {
		p = t;
		t = (key < (t->data.id)) ? t->left : t->right;
	}


	if (t == NULL)
	{
		printf("key is not in the tree");
		return;
	}

	if ((t->left == NULL) && (t->right == NULL)) {
		if(p!=NULL) {
			if (p->left == t)
				p->left = NULL;
			else
				p->right = NULL;
		}
		else
			*root = NULL;
	}
	else if ((t->left == NULL) || (t->right == NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL){
			if(p->left == t)
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}

	else {
		succ_p = t;
		succ = t->right;

		while(succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		if(succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		t->data.id = succ->data.id;
		strcpy(t->data.dept, succ->data.dept);
		strcpy(t->data.name, succ->data.name);
		strcpy(t->data.tel, succ->data.tel);
		t = succ;
	}
	free(t);
}


void preorder(TreeNode *root) // p271 코드 복사
{
     if (root) {
          printf("%d ", root->data);
          preorder(root->left);
          preorder(root->right);
     }
}
void print(TreeNode *root)
{
	printf("--------------------------\n");
	printf("학번: %d\n", root->data.id);
	printf("이름: %s\n", root->data.name);
	printf("전화번호: %s\n", root->data.tel);
	printf("학과: %s\n", root->data.dept);
	return;
}
void order(TreeNode *root)
{
	if(root == NULL)
		return;
	order(root->left);
	print(root);
	order(root->right);
}
/*
int search(TreeNode *root, int key)
{
	int decide;
	if(root == NULL) return FALSE;

	if(root->data.id == key) {
		print(root);
		return TRUE;
	}
		
	if (root->data.id < key)
		decide = search(root->right, key);
	else
		decide = search(root->left, key);
	return decide > 0;
}
*/

TreeNode *search (TreeNode *node, int key)
{
	while(node != NULL) {
		if(key == node->data.id) return node;
		else if(key < node->data.id)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

int main(void)
{
    element newNode ;
    TreeNode *root;
	char s;
	int num;
	TreeNode *searching;

	searching = (TreeNode *)malloc(sizeof(TreeNode));
	root = (TreeNode *)malloc(sizeof(TreeNode) * MAX_TREE_SIZE);
	root = NULL;

	do
	{
		fflush(stdin);
		printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit) : ");
		scanf("%c", &s);

		switch(s)
		{
		case 'i' : 
			printf("학번 입력: ");
			scanf("%d", &newNode.id);

			fflush(stdin);
			printf("이름 입력: ");
			scanf("%s", newNode.name);

			fflush(stdin);
			printf("전화번호 입력: ");
			scanf("%s", newNode.tel);

			fflush(stdin);
			printf("학과 입력: ");
			scanf("%s", newNode.dept);

			insert_node(&root, newNode);
			break;

		case 'd' :
			printf("삭제할 학번 입력: ");
			scanf("%d", &num);
			delete_node(&root, num);
			break;

		case 's' :
			printf("탐색할 학번 입력: ");
			scanf("%d", &num);

			searching = search(root, num);
			if(searching == NULL)
				printf("id가 %d인 학생은 없습니다.\n", num);
			else
				print(searching);
			break;

		case 'p' :
			printf("학생 정보 학번 순 출력\n");
			order(root);
			printf("\n");
			break;

		case 'c' :
			printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(root));
			break;
		}

	}while(s != 'q');
}