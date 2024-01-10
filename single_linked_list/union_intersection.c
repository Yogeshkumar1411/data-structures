 /*
*Name: Yogesh
*Date: 8/1/24
*program: union and intersction
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
		printf("data = %d\t",p->data);
		printf("address = %d\n",p->link);
		p = p->link;
	}	
}

struct node *intersect(struct node *ptr_1,struct node *ptr_2)
{
	int node;
	printf("Enter the node to be intersect with list_1\n");
	scanf("%d",&node);
	struct node *p_1 = ptr_1;
	struct node *p_2 = ptr_2;
	struct node *prev = NULL;
	while(node>1)
	{
		p_1 = p_1->link;
		node--;
	}
	while(p_2->link)
	{
		prev = p_2;
		p_2=p_2->link;
	}
	p_2->link = p_1->link;
	p_1->link = prev->link;
	return ptr_2;
}

struct node *getIntersection(struct node *ptr_1,struct node *ptr_2)
{
	while(ptr_2)
	{
		struct node *p = ptr_1;
		while(p)
		{
			if(p==ptr_2)
			{
				return ptr_2;
			}
			p=p->link;
		}
		ptr_2 = ptr_2->link;
	}
	return NULL;
}



struct node *getunion(struct node *ptr_1,struct node *ptr_2)
{
	struct node *uni_list = NULL;
	struct node *p = ptr_1;
	while(p)
	{
		uni_list = insert(uni_list,p->data);
		p = p->link;
	}
	p = ptr_2;
	while(p)
	{
		struct node *temp = uni_list;
		int flag = 0;
		while(temp)
		{
			if((p->data)==(temp->data))
			{
				flag = 1;
				break;
			}
			temp = temp->link;
		}
		if(flag==0)
		{
			uni_list = insert(uni_list, p->data);
		}
		p = p->link;
	}
	return uni_list;
}

int main()
{
	struct node *list_1 = NULL;
	struct node *list_2 = NULL;
	
	list_1 = insert(list_1,1);
	list_1 = insert(list_1,4);
	list_1 = insert(list_1,5);
	list_1 = insert(list_1,7);
	list_1 = insert(list_1,9);
	printf("****list_1****\n");
	print(list_1);
	
	list_2 = insert(list_2,2);
	list_2 = insert(list_2,4);
	list_2 = insert(list_2,6);
	printf("****list_2****\n");
	print(list_2);
	
	
	list_2 = intersect(list_1,list_2);
	printf("****list_1_after****\n");
	print(list_1);
	printf("****list_2_after****\n");
	print(list_2);
	
	struct node *intersection = getIntersection(list_1,list_2);
	
	if(intersection)
	{
		printf("intersect data = %d\n",intersection->data);
	}
	else
	{
		printf("No intersection\n");
	}
	
	
	struct node *union_list = getunion(list_1,list_2);
	printf("****union****\n");
	print(union_list);
	
	free(list_1);
	free(list_2);
	free(union_list);
	list_1 = NULL;
	list_2 = NULL;
	union_list = NULL;
	
	
}
