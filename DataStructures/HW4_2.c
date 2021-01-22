#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20	

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;


int get_node_count(TreeNode *node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + get_node_count(node->left) + get_node_count(node->right);
}


int get_maximum(TreeNode *node) {
	if(node->right != NULL)
		return get_maximum(node->right);
	return node->key;
}
int get_minimum(TreeNode *node) {
	if(node->left != NULL)
		return get_minimum(node->left);
	return node->key;
}

void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t, *n;

	t = *root;
	p = NULL;
	
	while(t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	n = (TreeNode *) malloc(sizeof(TreeNode));
	if(n == NULL) return;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	if (p != NULL){
		if (key < p->key) p->left = n;
		else			p->right = n;
	}
	else
		*root = n;
	
}

void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;


	while(t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
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

		t->key = succ->key;
		t = succ;
	}
	free(t);
}

void preorder(TreeNode *root) // p271 �ڵ� ����
{
     if (root) {
          printf("%d ", root->key);
          preorder(root->left);
          preorder(root->right);
		  
     }
}
void postorder(TreeNode *root) // p271 �ڵ� ����
{
     if (root) {
         
          postorder(root->left);
          postorder(root->right);
		   printf("%d ", root->key);
     }
}
void inorder(TreeNode *root) // p271 �ڵ� ����
{
     if (root) {
          
          inorder(root->left);
		  printf("%d ", root->key);
          inorder(root->right);
     }
}
void downorder(TreeNode *root) // p271 �ڵ� ����
{
     if (root) {
          downorder(root->right);
		  printf("%d ", root->key);
          downorder(root->left);
     }
}
int get_height(TreeNode *root)
{
	int height = 0;
	int Lheight, Rheight;

	if (root != NULL)
	{
		Lheight = get_height(root->left);
		Rheight = get_height(root->right);

		if(Lheight > Rheight)
			height = Lheight + 1;
		else
			height = Rheight + 1;
	}
	return height;
}
/*
int search(TreeNode *root, int key)
{
	int decide;
	if(root == NULL) return FALSE;

	if(root->key == key) return TRUE;
		
	if (root->key < key)
		decide = search(root->right, key);
	else
		decide = search(root->left, key);
	return decide > 0;
}
*/
TreeNode *search (TreeNode *node, int key)
{
	while(node != NULL) {
		if(key == node->key) return node;
		else if(key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}
int main(void)
{
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode) * MAX_TREE_SIZE);
    char s;
	int num;
	root = NULL;

	fflush(stdin);
	printf("Enter i(nsert), d(elete), s(earch), p(rint), h(eight), c(ount), m(ax), n(min), q(uit) :");
	scanf("%c", &s);

	while(s != 'q'){
	
		switch(s)
		{
		case 'i':
			printf("������ key�� �Է�: ");
			scanf("%d", &num);
			insert_node(&root, num);
			break;

		case 'd':
			printf("������ key�� �Է�: ");
			scanf("%d", &num);
			delete_node(&root, num);
			break;

		case 's':
			printf("Ž���� key�� �Է�: ");
			scanf("%d", &num);

			if (search(root, num) != NULL)
				printf("����\n");
			else
				printf("����\n");
			break;

		case 'p':
			preorder(root);


			printf("\n\n\n");
			inorder(root);
			printf("\n");
			downorder(root);
			printf("\n");
			break;

		case 'h':
			printf("Ʈ���� ���̴� %d\n", get_height(root));
			break;

		case 'c':
			printf("����� ������ %d\n", get_node_count(root));
			break;

		case 'm':
			printf("���� ū ���� %d\n", get_maximum(root));
			break;

		case 'n':
			printf("���� ���� ���� %d\n", get_minimum(root));
			break;
		}
	
		fflush(stdin);
		printf("Enter i(nsert), d(elete), s(earch), p(rint), h(eight), c(ount), m(ax), n(min), q(uit) :");
		scanf("%c", &s);
	}
}