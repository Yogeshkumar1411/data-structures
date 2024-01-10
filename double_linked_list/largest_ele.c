 /*
*Name: Yogesh
*Date: 8/1/24
*program: largest element in double linked list
*/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *insert(struct node *ptr,int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	if(ptr==NULL)
	{
		ptr = temp;
		return ptr;
	}
	else
	{
		struct node *p = ptr;
		while(p->next)
		{
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
		return ptr;
	}
}

void print(struct node *ptr)
{
	while(ptr)
	{
		//printf("prev = %d\t next = %d\t",ptr->prev,ptr->next);
		printf("data = %d\n",ptr->data);
		ptr = ptr->next;
	}
}


void max(struct node *ptr)
{
	int large = ptr->data;
	while(ptr->next)
	{
		printf("data_max = %d\n",large);
		ptr = ptr->next;
		if((ptr->data)>large)
		{
			large = ptr->data;
		}
	}
	printf("large is %d\n",large);
}

int main()
{
	struct node *head = NULL;
	head = insert(head,25);
	head = insert(head,7);
	head = insert(head,15);
	head = insert(head,8);
	head = insert(head,20);
	print(head);
	max(head);
}
