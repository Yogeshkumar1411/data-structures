 /*
*Name: Yogesh
*Date: 4/1/24
*program: implementing stack using linked list
*/
#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
struct stack
{
	int data;
	struct stack *link;
};
struct stack *stackPtr;
int stackSize_count = 0;
