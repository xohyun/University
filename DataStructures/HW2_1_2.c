#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode *link;
}StackNode;

typedef struct {
	StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType *s)
{
	return s->top == NULL;
}
int is_full(LinkedStackType *s)
{
	return 0;
}
void push (LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL)
	{
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else 
	{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
element pop(LinkedStackType *s)
{
	if(is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else
	{
		StackNode *temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
element peek (LinkedStackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr,"������ �������\n");
		exit(1);
	}
	else
	{
		return s->top->item;
	}
}
int main(void)
{
	LinkedStackType s;

	init(&s);

	push(&s, 5);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}