#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20	

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

//         root
//		  15
//	    4		 15
//  15	      16  25

//	root2
//	        15
//	   4		 15
//15            16  25
//                   28  

TreeNode n1={15,  NULL, NULL};
TreeNode n2={4,  &n1,  NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={15, &n3,  &n4};
TreeNode n6={15, &n2,  &n5};
TreeNode *root= &n6;

TreeNode m1={15,  NULL, NULL};
TreeNode m2={4,  &n1,  NULL};
TreeNode m3={16, NULL, NULL};
TreeNode m7 = {28, NULL, NULL}; // 추가
TreeNode m4={25, NULL, &m7}; // 변경
TreeNode m5={15, &m3,  &m4};
TreeNode m6={15, &m2,  &m5};
TreeNode *root2= &m6;
//p281 Quiz 01

int get_nonleaf_count(TreeNode *t) {//비단말노드의 개수
	if(t == NULL)
		return 0;
	else if(t->left == NULL && t->right == NULL)
		return 0;
	else
		return 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
}

int get_leaf_count(TreeNode *node)//단말노드
{
	int count = 0;
	if(node != NULL)
	{
		if(node->left == NULL && node->right == NULL) return 1;
		else count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

//p281 Quiz 02
int equal(TreeNode *t1, TreeNode *t2) {
	if (t1 == NULL && t2 == NULL)
		return 1;
	else if(t1 == NULL)
		return 0;
	else if(t2 == NULL)
		return 0;
	else {
		if (t1->data != t2->data) return 0;
		else if( equal(t1->left, t2->left) && equal(t1->right, t2->right)) return 1;
	}
}//if (equal(t1->left, t2->left) && equal(t1->right, t2->right))

//p308 #25
int get_oneleaf_count(TreeNode *node) {
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else if (node->left == NULL)
		return 1 + get_oneleaf_count(node->right);
	else if (node->right == NULL)
		return 1 + get_oneleaf_count(node->left);
	else
		return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
}

//p308 #26 
int get_twoleaf_count(TreeNode *node) {
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else if (node->left == NULL)
		return get_twoleaf_count(node->right);
	else if (node->right == NULL)
		return get_twoleaf_count(node->left);
	else
		return get_twoleaf_count(node->left) + 1 + get_twoleaf_count(node->right);
} 

//p308 #27
int get_max(TreeNode *node) {
	int max, Lmax, Rmax;
	if (node)
	{
		max = INT_MIN;
		Lmax = get_max(node->left);
		Rmax = get_max(node->right);
		if (Lmax > Rmax)
			max = Lmax;
		else
			max = Rmax;

		if (max < node->data)
			max = node->data;
		return max;
	}
	else
		return INT_MIN;
}
int get_min(TreeNode *node) {
	int min, Lmin, Rmin;
	if (node)
	{
		min = INT_MAX;
		Lmin = get_min(node->left);
		Rmin = get_min(node->right);
		if (Lmin < Rmin)
			min = Lmin;
		else
			min = Rmin;

		if (min > node->data)
			min = node->data;
		return min;
	}
	else
		return INT_MAX;
}

//p308 #30
void node_increase(TreeNode *node)
{
	if (node == NULL)
		return;

	node->data++;
	node_increase(node->left);
	node_increase(node->right);

	/*
	if (node)
	{
		node->data++;
		node_increase(node->left);
		node_increase(node->right);
	}
	return; 
	*/
}

void preorder(TreeNode *root) // p271 코드 복사
{
     if (root) {
          printf("%d ", root->data);
          preorder(root->left);
          preorder(root->right);
     }
}

TreeNode *copy(TreeNode *node)
{
	TreeNode *clone;
	if(node == NULL)
		return NULL;
	else {
		clone = (TreeNode *)malloc(sizeof(TreeNode) * MAX_TREE_SIZE);
		clone->left = copy(node->left);
		clone->right = copy(node->right);
		clone->data = node->data;
	}
	return clone;
}
int main(void)
{
    TreeNode *result[MAX_TREE_SIZE] ;
	TreeNode *clone ;
	int i, num ;

    printf("트리 root중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
    printf("트리 root2중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
     
	printf("트리 root중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
    printf("트리 root2중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));

    printf("트리 root중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
    printf("트리 root2중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));

    printf("트리 root에서 가장 큰 수는 %d.\n", get_max(root));
    printf("트리 root2에서 가장 큰 수는 %d.\n", get_max(root2));

	printf("트리 root에서 가장 작은 수는 %d.\n", get_min(root));
    printf("트리 root2에서 가장 작은 수는 %d.\n", get_min(root2));

	/*
	num = search(root, 15, result);
	for (i = 0; i < num; i++) 
		printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");
	*/

	preorder(root);printf("\n");
	
    node_increase(root);
    preorder(root);
	 
	printf("\n");
	
	printf("%s\n", equal(root, root) ? "같다": "다르다");
    printf("%s\n", equal(root2, root2) ? "같다": "다르다");
    printf("%s\n", equal(root, root2) ? "같다": "다르다");
	

    clone = copy(root) ;
    preorder(root) ;
	printf("\n");
    preorder(clone) ; 
	printf("\n");
}
