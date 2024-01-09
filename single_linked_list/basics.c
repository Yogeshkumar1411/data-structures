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

struct node *delete_at_end(struct node *ptr)
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
	return p;
}


struct node *insert_at_front(struct node *ptr,int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = ptr;
	ptr = temp;
	return ptr;
}


struct node *delete_at_front(struct node *ptr)
{
	struct node *temp = ptr;
	ptr=ptr->link;
	free(temp);
	temp = NULL;
	return ptr;
}

int find_length(struct node *ptr)
{
	int count = 0;
	struct node *temp = ptr;
	while(temp)
	{
		count++;
		temp = temp->link;
	}
	return count;
}


int find_length_rec(struct node *ptr)
{	
//	printf("temp data = %d\n",temp->data);
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		return 1+find_length_rec(ptr->link);
	}
}


struct node *insert_after_node(struct node *ptr, int data, int node)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	struct node *p = ptr;
	while(node>1)
	{
		p = p->link;
		node--;
	}
	temp->link=p->link;
	p->link = temp;
	//ptr = p;
	return ptr;
}


struct node *delete_node_after(struct node *ptr, int node)
{
	struct node *temp = ptr;
	while(node>1)
	{
		temp=temp->link;
		node--;
	}
	temp->link = temp->link->link;
	return ptr;
	
}


struct node *reverse_loop(struct node *ptr,struct node *next,struct node *prev)
{
	//struct node *temp = ptr;
	//printf("loop\n");
	while(ptr!=NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	ptr = prev;
	return ptr;
}

struct node *reverse_rec(struct node *ptr,struct node *next,struct node *prev)
{	
	if(ptr==NULL)
	{
		return prev;
	}
	else
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
		return reverse_rec(ptr,next,prev);	
	}
}

void recursion_print(struct node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		recursion_print(ptr->link);
		printf("rec print data = %d\n",ptr->data);
	}
}

int main()
{
	int choice,data,node;
	struct node *head = NULL;
	while(1)
	{
		printf("\n1. insert_at_end\n2. print\n3. delete_at_end\n4. insert_at_front\n5. delete_at_front\n6. Length\n7. length using recursion\n8. insert after given node\n9. Delete node after\n10. Reverse\11. Recursion print\nn0. exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("insert_at_end\n");
				scanf("%d",&data);
				head = insert_at_end(head,data);			
				break;
			case 2:
				printf("print\n");
				print(head);
				break;
			case 3:
				printf("delete_at_end\n");
				head = delete_at_end(head);
				break;
			case 4:
				printf("insert at front\n");
				scanf("%d",&data);
				head = insert_at_front(head,data);	
				break;
			case 5:
				printf("delete at front\n");
				head = delete_at_front(head);
				break;	
			case 6:
				printf("Length\n");
				printf("length = %d\n",find_length(head));
				break;
			case 7:
				printf("Length using recursion\n");		
				printf("rec length = %d\n",find_length_rec(head));
				break;
			case 8:
				printf("Insert a node after given node\n\ninsert data and node to be entered\n");
				scanf("%d %d",&data,&node);
				head = insert_after_node(head,data,node);
				break;
			case 9:
				printf("Delete node after\n");
				scanf("%d",&node);
				head = delete_node_after(head,node);
				break;
			case 10:
				printf("Reverse\n1. Loop\n2. recursive\n");
				int method;
				scanf("%d",&method);
						struct node *next = NULL;
						struct node *prev = NULL;
				switch(method)
				{
					case 1:
						head = reverse_loop(head,next,prev);
						break;
					case 2:
						head = reverse_rec(head,next,prev);
						break;
					default:
						printf("Invalid reverse method\n");	
						break;	
				}
				break;
			case 11:
				printf("Print recursion\n");
				recursion_print(head);
				break;
			case 0:
					exit(0);
			default:
				printf("invalid\n");	
				break;
		}
	}	
	
}
