 /*
*Name: Yogesh
*Date: 8/1/24
*program: Program to Check if Two Trees are Identical
*/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}


int identical(struct node *ptr_1, struct node *ptr_2)
{
	if(ptr_1==NULL&&ptr_2==NULL)
	{
		return 1;
	}
	if(ptr_1!=NULL&&ptr_2!=NULL)
	{
		return ptr_1->data==ptr_2->data && identical(ptr_1->left,ptr_2->left) && identical(ptr_1->right,ptr_2->right);
	}
	return 0;
}

int main()
{
	struct node *head_1 = NULL;
	struct node *head_2 = NULL;	
	head_1 = insert(5);
	head_1->left = insert(47);
	head_1->right = insert(40);
	head_1->left->left = insert(50);
	head_1->left->right = insert(10);
	head_1->right->left = insert(30);
	head_1->right->right = insert(20);
	
	
	head_2 = insert(5);
	head_2->left = insert(47);
	head_2->right = insert(40);
	head_2->left->left = insert(50);
	head_2->left->right = insert(10);
	head_2->right->left = insert(30);
	head_2->right->right = insert(20);
	
	if(identical(head_1,head_2))
	{
		printf("Both are identiacl\n");
	}
	else
	{
		printf("Not identical\n");
	}
}
