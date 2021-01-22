#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 20
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;
void init(HeapType *h)
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i/2].key))
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
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void preorder(HeapType *h, int root)
{
	if (root <= h->heap_size)
	{
		printf("%d ", h->heap[root].key);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}
void print_heap(HeapType *h)
{
	int i, j = 1;

	for(i = 1; i <= h->heap_size; i++){
		if (j * 2 == i)
		{
			printf("\n");
			j = i;
		}
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
	/*int j = 1, i = 1;

	while (i <= h->heap_size)
	{
		printf("%d ", h->heap[i].key);
		if (i == 1)
			printf("\n");
		if (j * 2 + 1 == i)
		{
			printf("\n");
			j = i;
		}
		i++;
	}
	printf("\n");*/
}
int find(HeapType *h, int root, int key)
{
	if (h->heap[root].key == key)
		return root;
	if (h->heap[root * 2].key < key && h->heap[root * 2 + 1].key < key)
		return -1;
	find(h, root * 2, key);
	find(h, root * 2 + 1, key);
}
int find2(HeapType *h, int key)
{
	int i, j = 1, flag = 0;
	if (key > h->heap[1].key)
		return -1;
	for (i = 1; i <= h->heap_size; i++)
	{
		if (key == h->heap[i].key)
			return i;
		if (key > h->heap[i].key)
		{
			if (j * 2 + 1 == i)
			{
				if (key > h->heap[i].key && flag != 1)
					return -1;
				else
				{
					j = i;
					flag = 0;
				}
			}
			else
				flag = 1;
		}
	}
	return -1;
}
void print_sorted_value(HeapType h)
{
	int i;
	HeapType h2;

	init(&h2);

	for (i = 1; i <= h.heap_size; i++)
		insert_max_heap(&h2, h.heap[i]);
	for (i = 1; i <= h.heap_size; i++)
		printf("%d ", delete_max_heap(&h2));
	printf("\n");
}
void modify_priority(HeapType *h, int oldkey, int newkey)
{
	int i, key = 0, parent, child;
	element temp;
	for (i = 1; i <= h->heap_size; i++)
		if (h->heap[i].key == oldkey)
		{
			key = 1;
			h->heap[i].key = newkey;
			break;
		}
	temp.key = h->heap[i].key;
	parent = i / 2;
	child = i * 2;
	if (key == 1)
	{
		if (temp.key > parent)
		{
			while ((i != 1) && (temp.key > h->heap[i / 2].key))
			{
				h->heap[i] = h->heap[i / 2];
				i /= 2;
			}
			h->heap[i] = temp;
		}
		else
		{
			while (i <= h->heap_size)
			{
				if ((child < h->heap_size) && h->heap[child].key < h->heap[child + 1].key)
					child++;
				if(temp.key >= h->heap[child].key)
					break;
				h->heap[i] = h->heap[child];
				i = child;
				child *= 2;
			}
			h->heap[parent] = temp;
		}
	}
}
void read_heap(HeapType *h, char *filename)
{
	int state;
	element n;
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename);
		return;
	}
	
	while (fscanf(fp, "%d\n", &n.key) != EOF)
		insert_max_heap(h, n);

	state = fclose(fp);
	if (state != 0)
		printf("file close error!\n");
}
void write_heap_array(HeapType *h, char *filename)
{
	FILE *fp;
	int i, state;
	char ch;

	if (filename == NULL)
		fp = stdout;
	else
	{
		fp = fopen(filename, "w");
		if (fp == NULL)
		{
			fprintf(stderr, "파일 %s을 열 수 없음!\n", filename);
			return;
		}
	}
	for (i = 1; i <= h->heap_size; i++)
	{
		ch = h->heap[i].key;
		fprintf(fp, "%d\n", ch);
	}
	state = fclose(fp);
	if (state != 0)
		printf("file close error!\n");
}
void write_descending_order(HeapType *h, char *filename)
{
	FILE *fp;
	HeapType h2;
	int i;
	char ch;
	
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename);
		return;
	}
	init(&h2);
	for (i = 1; i <= h->heap_size; i++)
		insert_max_heap(&h2, h->heap[i]);
	for (i = 1; i <= h->heap_size; i++)
	{
		ch = delete_max_heap(&h2).key;
		printf("%d %d %d\n", i, ch, h->heap_size);
		fprintf(fp, "%d\n", ch);
	}
	printf("\n");
}
int main(void)
{
	HeapType heap;
	int i;
	element e1 = {20}, e2 = {40};

	init(&heap);

	read_heap(&heap, "input.txt");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);

	write_heap_array(&heap, "heapArray.txt");
	write_descending_order(&heap, "sorted.txt");
}