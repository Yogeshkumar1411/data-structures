 /*
*Name: Yogesh
*Date: 8/1/24
*program: C Program to Count Leaf Nodes in a Binary Tree
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

int count = 0;
int count_node_tree(struct node *ptr_1)
{
	
	if(ptr_1==NULL)
	{
		return 1;
	}
	else
	{
		
		count_node_tree(ptr_1->left);
		if((ptr_1->left==NULL)&&(ptr_1->right==NULL))
		{
			count++;
		}
		count_node_tree(ptr_1->right);
	}
	return count;
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
	
	printf("leafnode count = %d\n",count_node_tree(head_1));
	
}
