#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0;

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while((i != 1) && (item.key > h->heap[i/2].key))
	{
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size){
		if((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if(temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void preorder(HeapType *h, int root)
{
	if(root > h->heap_size)
		return;

	printf("%d ",h->heap[root].key);
	preorder(h, root * 2);
	preorder(h, root * 2 + 1);
}
int find(HeapType*h, int root, int key)
{
	int decide = 0, num = root;
	if(h->heap[root].key == key)
		return root;
	if (root > h->heap_size)
		return NULL;

	num = find(h, root * 2, key);
	if (num != NULL) decide = num;
	num = find(h, root * 2 + 1, key);
	if (num != NULL) decide = num;

	return decide;
}
int find2(HeapType *h, int key)
{
	int i;
	int max = INT_MAX, min = INT_MIN;

	for (i = 1; i <= h->heap_size; i++)
	{
		if (h->heap[i].key == key)
			return i;
		if (key > h->heap[i].key)
			break;
	}
	return NULL;
}
void print_sorted_value(HeapType h)
{
	int i;
	HeapType hh;
	hh.heap_size = 0;

	for (i = h.heap_size; i > 0; i--)
	{
		hh.heap[i] = delete_max_heap(&h);
		printf("%d ", hh.heap[i].key);
	}
	printf("\n");
}
void print_heap(HeapType *h)
{
	int i, j = 1;

	for(i = 1; i <= h->heap_size; i++){
		if(j * 2 == i)
		{
			printf("\n");
			j = i;
		}
		printf("%d ", h->heap[i].key);
	}

	printf("\n");

	/*
	for(i = 1; i <= h->heap_size; i++){
		num = i;
		while(num != 1 && num > 0){
			if(num == 2 && nnum == 0){
				printf("\n");
				break;
			}
			nnum = num % 2;
			num /= 2;
		}
		printf("%d " , h->heap[i].key);
	}

	*/
}
void modify_priority(HeapType *h, int oldkey, int newkey)
{

}

int main(void)
{
	element e1 = {10}, e2 = {5}, e3 = {30}, eA = {9}, eB = {19}, eC= {39};
	element e4;
	HeapType heap;
	int num;

	init(&heap);
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);
	preorder(&heap, 1);
	printf("\n");
	print_heap(&heap);

	//find 함수 테스트
	printf("\n");
	num = find(&heap, 1, 39);
	if (num == NULL)
		printf("없습니다.\n");
	else
		printf("39는 인덱스 %d에 있습니다.\n", num);


	num = find(&heap, 1, 19);
	if (num == NULL)
		printf("19는 없습니다.\n");
	else
		printf("19는 인덱스 %d에 있습니다.\n", num);


	num = find(&heap, 1, 20);
	if (num == NULL)
		printf("20은 없습니다.\n");
	else
		printf("20은 있습니다.\n");


	//find2 테스트
	num = find2(&heap, 19);
	if (num == NULL)
		printf("없습니다.\n");
	else
		printf("있습니다.\n");


	num = find2(&heap,20);
	if (num == NULL)
		printf("없습니다.\n");
	else
		printf("있습니다.\n");

	//print_sorted_value함수 테스트
	printf("\n");
	print_sorted_value(heap);
	
	
	e4 = delete_max_heap(&heap);
	printf("\n<%d>\n", e4.key);
	print_heap(&heap);

	e4 = delete_max_heap(&heap);
	printf("\n<%d>\n", e4.key);
	print_heap(&heap);
}