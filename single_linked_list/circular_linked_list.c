 /*
*Name: Yogesh
*Date: 8/1/24
*program: Convert a Singly Linked List to Circular Linked List
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *insert(struct node *ptr,int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	if(ptr==NULL)
	{
		ptr=temp;
	}
	else
	{
		struct node *p = ptr;
		while(p->link)
		{
			p=p->link;
		}
		p->link = temp;
	//	ptr = p;
	}
	//printf("data = %d\n",ptr->data);
	return ptr;
}

void print(struct node *ptr)
{
	struct node *p = ptr;
	while(p)
	{
		printf("data = %d\n",p->data);
		p = p->link;		
	}	
}

struct node *circular(struct node *ptr)
{
	struct node *p = ptr;
	while(p->link)
	{
		p = p->link;
	}
	p->link = ptr;
	return ptr;
}

int main()
{
	struct node *head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,4);
	head = insert(head,5);
	printf("before\n");
	print(head);
	printf("after\n");
	head = circular(head);
	print(head);
}
