 /*
*Name: Yogesh
*Date: 8/1/24
*program: Program to Find Height of a Binary Tree
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


int height_of_tree(struct node *ptr_1)
{
	if(ptr_1==NULL)
	{
		return 0;
	}
	else
	{
		int lHeight = height_of_tree(ptr_1->left);
		int rHeight = height_of_tree(ptr_1->right);
		
		if(lHeight>rHeight)
		{
			return lHeight+1;
		}
		else
		{
			return rHeight+1;
		}
	}
}

int main()
{
	struct node *head_1 = NULL;
	head_1 = insert(5);
	head_1->left = insert(47);
	head_1->right = insert(40);
	head_1->left->left = insert(50);
	head_1->left->right = insert(10);
	head_1->right->left = insert(30);
	head_1->right->right = insert(20);
	head_1->right->right->right = insert(21);
	
	printf("Height of the tree = %d\n",height_of_tree(head_1));
	
}
