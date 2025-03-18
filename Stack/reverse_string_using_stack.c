#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int top;
	unsigned capacity;
	char* text;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	
	stack -> top = -1;
	stack -> capacity = capacity;
	stack -> text = (char*)malloc(sizeof(char)*capacity);
	
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
	if(isFull(stack))
		return ;
	stack->text[++stack->top] = item;
}

char pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return;
	return stack->text[stack->top--];
}


void reverse(char str[])
{
	
	int n = strlen(str),i;
	
	struct Stack* s = createStack(n);
	
	//push
	for(i=0; i<n; i++)
	{
		push(s,str[i]);
	}
	
	//pop
	for(i=0;i<n;i++)
	{
		str[i] = pop(s);
	}
}

void main()
{
	char str[] = "Hello world";
	
	reverse(str);
	
	printf("The reverse of the string is %s",str);
}
