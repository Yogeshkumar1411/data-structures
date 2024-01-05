//#include"stack_using_ll_header.h"
#include"stack_using_ll_functions.c"
#define PUSH 1
#define POP 2
#define ISEMPTY 3
#define PEEK 4
#define DISPLAY 5
#define ISFULL 6
#define GETSTACKSIZE 7
int main()
{
	int operation;
	initiate_stack();
	while(1)
	{
		printf("\n\n1. push\n2. pop\n3. isEmpty\n4. Peek\n5. display\n6. isFull\n7. get stack size\n\n");
		scanf("%d",&operation);
		switch(operation)
		{
			case PUSH:
				printf("push\n");
				printf("Enter the data that want to push\n");
				int data;
				scanf("%d",&data);
				push(data);
				break;
			case POP:
				printf("pop\n");
				pop();
				break;
			case ISEMPTY:
				printf("isEmpty\n");
				if(isEmpty())
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("Stack is not empty\n");
				}
				break;
			case PEEK:
				printf("peek\n");
				peek();
				break;
			case DISPLAY:
				printf("display\n");
				displayStack();
				break;
			case ISFULL:
				printf("isfull\n");
				if(isFull())
				{
					printf("Stack is full\n");
				}
				else
				{
					printf("Stack is not full\n");
				}	
				break;
			case GETSTACKSIZE:
				printf("\nTotal stack size = %d\n",STACKSIZE);
				printf("\nCurrent size = %d\n",stackSize_count);
				break;				
			default:
				printf("invaild\n");
				break;	
		}
	}
	
}
