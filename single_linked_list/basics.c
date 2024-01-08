 /*
*Name: Yogesh
*Date: 8/1/24
*program: Inserting a node at front and end of linked List
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node *insert_at_end(struct node *ptr,int data)
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

void delete_at_end(struct node *ptr)
{
	struct node *p = ptr;
	while(p->link->link)
	{
		p = p->link;
	}
	struct node *temp = p->link;
	p->link = NULL;
	free(temp);
	temp = NULL;
}

int main()
{
	int choice;
	struct node *head = NULL;
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
				head = insert_at_end(head,data);			
				break;
			case 2:
				printf("print\n");
				print(head);
				break;
			case 3:
				printf("delete\n");
				delete_at_end(head);
				break;
			case 4:
					exit(0);
			default:
				printf("invalid\n");	
				break;
		}
	}	
	
}
