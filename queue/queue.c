 /*
*Name: Yogesh
*Date: 8/1/24
*program: C Program to Implement a Queue using Linked List
*/
#include<stdio.h>
#include<stdlib.h>


struct queue
{
	int data;
	struct queue *link;
};

struct queue *headPtr = NULL;
struct queue *tailPtr = NULL;

struct queue *insert(struct queue *queuePtr,int data)
{
	struct queue *temp = malloc(sizeof(struct queue));
	temp->data = data;
	temp->link = NULL;
	if(headPtr==NULL)
	{
		headPtr = temp;
		tailPtr = temp;
		printf("tptr = %d\n",tailPtr->data);
		queuePtr = tailPtr;
	}
	else
	{
		tailPtr->link = temp;
		tailPtr = temp;
		printf("tptrelse = %d\n",tailPtr->data);
		queuePtr = tailPtr;
	}
	return queuePtr;
}



void print(struct queue *temp)
{
	struct queue *ptr = headPtr;
	while(ptr)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->link;
	}
}


void delete(struct queue *temp)
{
	struct queue *ptr = headPtr;
	headPtr = headPtr->link;
	free(ptr);
	ptr=NULL;
}

int main(){
	int choice;
	struct queue *queuePtr = NULL;
	while(1)
	{
		printf("\n1. insert\n2. print\n3. delete\n4. exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("insert\n");
				int data;
				scanf("%d",&data);
				queuePtr = insert(queuePtr,data);			
				break;
			case 2:
				printf("print\n");
				print(queuePtr);
				break;
			case 3:
				printf("delete\n");
				delete(queuePtr);
				break;
			case 4:
					exit(0);
			default:
				printf("invalid\n");	
				break;
		}
	}
}
