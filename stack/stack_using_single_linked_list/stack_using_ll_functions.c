#include"stack_using_ll_header.h"
void initiate_stack()
{
	stackPtr = NULL;
}
///////////////////////////////
int isFull()
{
	if(stackSize_count>STACKSIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int data)
{
	if(isFull())
	{
		printf("Stack is full\n");
	}
	else
	{
		stackSize_count++;
		struct stack *ptr = malloc(sizeof(struct stack));
		ptr->data = data;
		if(stackPtr==NULL)
		{
			stackPtr = ptr;
			stackPtr->link = NULL;
		
		}
		else
		{
			ptr->link = stackPtr;
			stackPtr = ptr;
		}
	}
	
}
///////////////////////////////////////
int isEmpty()
{
	if(stackPtr==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////
void displayStack()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		struct stack *ptr = stackPtr;
		while(ptr)
		{
			printf("data = %d\n",ptr->data);
			ptr = ptr->link;
		}
	}
}
/////////////////////////////////////
void pop()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		stackSize_count--;
		struct stack *ptr = stackPtr;
		stackPtr = stackPtr->link;
		free(ptr);
	}
}
//////////////////////////////////
void peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d\n",stackPtr->data);
	}
}
