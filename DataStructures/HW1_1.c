//��ǻ���а� 20170988 �Ѽ���
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct{
	element list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(ArrayListType *L)
{
	L->length = 0;
}
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}
void display(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->length; i++)
		printf("%d-->", L->list[i]);
	printf("����Ʈ��\n");
	return;
}
void add(ArrayListType *L, int position, element item)
{
	if(!is_full(L) && (position >= 0) && (position <= L->length))
	{
		int i;

		for (i = (L->length - 1); i >= position; i--)
			L->list[i + 1] = L->list[i];
		
		L->list[position] = item;
		L->length++;
	}
}
element delete(ArrayListType *L, int position)
{
	int i;
	element item;

	if (position < 0 || position >= L->length) error("��ġ ����");
	item = L->list[position];

	for(i = position; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];

	L->length--;
	return item;
}

void clear(ArrayListType *L)
{
	L->length = 0;
}
void add_first(ArrayListType *L, element item)
{
	int i;
	for (i = L->length -1; i >= 0; i--)
		L->list[i + 1] = L->list[i];
	L->list[0] = item;
	L->length++;
	return;
}
void add_last(ArrayListType *L, element item)
{
	L->list[L->length] = item;
	L->length++;
	return;
}
int get_length(ArrayListType *L)
{
	return L->length;
}
element get_entry(ArrayListType *L, int pos)
{
	return L->list[pos];
}
void replace(ArrayListType *L, int pos, element item)
{
	L->list[pos] = item;
}
int is_in_list(ArrayListType *L, element item)
{
	int i;
	
	for (i = 0; i < L->length; i++)
		if (item == L->list[i])
			return 1;
	return 0;
}
void delete_by_key(ArrayListType *L, element key)
{
	int i;
	for (i = 0; i < L->length - 1; i++)
		if (L->list[i] == key)
		{
			delete(L, i);
			return;
		}
	printf("�����Ϸ��� key�� %d�� ����Ʈ�� �����ϴ�\n", key);
	return;
}
int main(void)
{
	ArrayListType list1;
	ArrayListType *plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);

	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
		init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);

     printf("-�� ���Ĵ� HW1_1���� �߰��� �Լ��� �׽�Ʈ-\n");
     
     clear(&list1); display(&list1);

     add_first(plist, 35); display(plist);
     add_last(plist, 5); display(plist);

     printf("���̴� %d\n", get_length(plist));
     printf("3��° ����Ÿ�� %d\n", get_entry(plist, 2));
     replace(plist, 2, 22); display(plist);
     printf("20�� ����Ʈ�� %s\n", is_in_list(plist, 20)? "�ֽ��ϴ�": "�����ϴ�");
     printf("22�� ����Ʈ�� %s\n", is_in_list(plist, 22)? "�ֽ��ϴ�": "�����ϴ�");
     
     delete_by_key(plist, 20); display(plist);
     delete_by_key(plist, 22); display(plist);
}