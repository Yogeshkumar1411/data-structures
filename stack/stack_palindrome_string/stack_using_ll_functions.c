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
int pop()
{
	int res;
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		stackSize_count--;
		struct stack *ptr = stackPtr;
		res = stackPtr->data;
		stackPtr = stackPtr->link;
		free(ptr);
		return res;
	}
}
//////////////////////////////////
int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return stackPtr->data;
	}
}
//////////////////////////////////////
void push_rec(int data)
{
	if(isEmpty())
	{
		push(data);
	}
	else
	{
		int temp = pop();
		push_rec(data);
		
		push(temp);
	}
}
int reverse()
{
	if(isEmpty()==0)	
	{
		int data = pop();
		reverse();
		
		//printf("temp = %d\n",temp);
		push_rec(data);
		//printf("rev %d\n",data);
	}
	
}
