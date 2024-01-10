 /*
*Name: Yogesh
*Date: 8/1/24
*program: size of a binary tree
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


int sizeofTree(struct node *ptr)
{
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		return sizeofTree(ptr->left)+1+sizeofTree(ptr->right);
	}
}

int main()
{
	struct node *head = NULL;
	head = insert(5);
	head->left = insert(47);
	head->right = insert(40);
	head->left->left = insert(50);
	head->left->right = insert(10);
	head->right->left = insert(30);
	head->right->right = insert(20);
	printf("size = %d\n",sizeofTree(head));
}
