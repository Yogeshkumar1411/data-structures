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

/*program to insert a node at end*/
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

/*program to print the nodes*/
void print(struct node *ptr)
{
	struct node *p = ptr;
	while(p)
	{
		printf("data = %d\n",p->data);
		p = p->link;
	}	
}

/*program to delete the node at end*/
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

/*program to insert node at front*/
struct node *insert_at_front(struct node *ptr,int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = ptr;
	ptr = temp;
	return ptr;
}

/*program to delete node at front*/
struct node *delete_at_front(struct node *ptr)
{
	struct node *temp = ptr;
	ptr=ptr->link;
	free(temp);
	temp = NULL;
	return ptr;
}

/*Find Length of a Linked List using Loop*/
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

/*Find Length of a Linked List using Recursion*/
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

/*Program to insert the node after given node*/
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

/*Program to delete the node after given node*/
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

/*Program to Reverse a Linked List using Loop*/
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

/*Program to Reverse a Linked List using Recursion*/
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


/*Print a Linked List in Reverse Order using Recursion*/
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

/*Program to Print Alternate Nodes of Linked List*/
void print_alternate(struct node *ptr)
{
	while(ptr)
	{
		printf("alter data = %d\n",ptr->data);
		ptr = ptr->link->link;
	}
}

/*Program to Find Nth Node from the End of a Linked List*/
void print_from_end(struct node *ptr,int node)
{
	struct node *temp = ptr;
	int len = 0;
	while(temp)
	{
		temp=temp->link;
		len++;
	}
	temp=ptr;
	int i;
	for(i=1;i<len-node+1;i++)
	{
		temp = temp->link;
	}
	printf("print_from_end %d\n",temp->data);
}


/*C Program to Find Middle Node of a Linked List*/
void find_mid_node(struct node *ptr)
{
	struct node *temp = ptr;
	int len = 0;
	while(temp)
	{
		temp=temp->link;
		len++;
	}
	int mid = len/2;
	temp = ptr;
	int i=0;
	for(i=0;i<mid;i++)
	{
		temp = temp->link;
	}
	printf("mid_node = %d\n",temp->data);	
}


/*Program to Search an Element in Linked List using Loop*/
int element_search_loop(struct node *ptr,int element)
{
	struct node *temp = ptr;
	int node = 0;
	while(element!=temp->data)
	{
		temp = temp->link;
		node++;
	}
	if(element==temp->data)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

/*Program to Search an Element in Linked List using Recursion*/
int element_search_rec(struct node *ptr,int element)
{
	if(ptr->data==element)
	{
		return 1;
	}
	if(ptr==NULL)
	{
		return 0;
	}
	return element_search_rec(ptr->link,element);
}


int main()
{
	int choice,data,node,method;//choice->parent switch case; data->insert,find; node->insertafter,find; method->child switch
	struct node *head = NULL;
	while(1)
	{
		printf("\n1. insert_at_end\n2. print\n3. delete_at_end\n4. insert_at_front\n5. delete_at_front\n6. Length\n7. length using recursion\n8. insert after given node\n9. Delete node after\n10. Reverse\n11. Recursion print\n12. alternate print\n13. print Nth node from end\n14. find mid node\n15. search element\n0. exit\n");
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
			case 12:
				printf("Print alternate nodes\n");
				print_alternate(head);
				break;
			case 13:
				printf("Print nth node from end\n");
				scanf("%d",&node);
				print_from_end(head,node);
				break;
			case 14:
				printf("find mid node\n");
				find_mid_node(head);
				break;
			case 15:
				printf("1. loop\n2. Recursive\n");
				scanf("%d",&method);
				printf("Enter the element that need to search\n");
				scanf("%d",&data);
				switch(method)
				{
					case 1:
						element_search_loop(head,data)?printf("element is there\n"):printf("Element not there\n");
						break;
					case 2:
						element_search_rec(head,data)?printf("element is there\n"):printf("Element not there\n");
						break;	
				}
				break;		
			case 0:
					exit(0);
			default:
				printf("invalid\n");	
				break;
		}
	}	
	
}
