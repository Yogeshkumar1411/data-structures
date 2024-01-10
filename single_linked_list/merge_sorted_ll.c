 /*
*Name: Yogesh
*Date: 8/1/24
*program: Merge Two Sorted Linked List
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


struct node *merge(struct node *ptr_1,struct node *ptr_2)
{
	struct node *ptr = ptr_1;
	while(ptr->link)
	{
		ptr = ptr->link;
	}
	if((ptr->data)<(ptr_2->data))
	{
		ptr->link = ptr_2;
		return ptr_1;
	}
	else
	{
		struct node *temp_1 = NULL;
		struct node *prev = NULL;
		
	while(ptr_2->link)
	{	
		int flag = 0;
		temp_1 = ptr_2;
		ptr = ptr_1;
		//printf("ptr_hi = %d\n",ptr->data);
		while(ptr)
		{
			if((ptr->data)>(temp_1->data))
			{
				flag = 1;
				break;
			}
			prev = ptr;			
			ptr=ptr->link;
		}
		//printf("ptr_bye = %d\n",ptr->data);
		if(flag==1)
		{
			struct node *new_node = malloc(sizeof(struct node));
			new_node->data = temp_1->data;
			new_node->link = prev->link;
			prev->link = new_node;
			ptr_2 = ptr_2->link;		
		}
	}
		//free(ptr_2);
		return ptr_1;
	}

}


int main()
{
	struct node *list_1 = NULL;
	struct node *list_2 = NULL;
	
	list_1 = insert(list_1,1);
	list_1 = insert(list_1,2);
	list_1 = insert(list_1,3);
	list_1 = insert(list_1,7);
	list_1 = insert(list_1,9);
	printf("****list_1****\n");
	print(list_1);
	
	list_2 = insert(list_2,1);
	list_2 = insert(list_2,4);
	list_2 = insert(list_2,4);
	list_2 = insert(list_2,8);
	list_2 = insert(list_2,9);
	printf("****list_2****\n");
	print(list_2);
	
	
	list_1 = merge(list_1,list_2);
	printf("After merge\n");
	print(list_1);
}
