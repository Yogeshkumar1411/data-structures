#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACKSIZE 50

int stackCountBytes = 0;

struct Stack
{
	char data;
	struct Stack *link;
};

struct Stack *sPtr = NULL;

void push(char data)
{
	if(stackCountBytes<STACKSIZE)
	{
		struct Stack *temp = malloc(sizeof(struct Stack));
		temp->	data = data;
		if(sPtr==NULL)
		{
			sPtr = temp;
			sPtr->link = NULL;
		}
		else
		{
			temp->link = sPtr;
			sPtr = temp;
		}
		stackCountBytes++;
	}
}

char pop()
{
	if(stackCountBytes>=0)
	{
		struct Stack *temp = sPtr;
		char res = sPtr->data;
		sPtr = sPtr->link;
		free(temp);
		stackCountBytes--;
		return res;
	}
}

void print()
{
	struct Stack *temp = sPtr;
	while(temp)
	{
		printf("data = %c\n",temp->data);
		temp = temp->link;
	}
}

int check_palindrome(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		push(str[i]);
	}
	int mid = len/2;
	i=0;
	while(i<mid)
	{
		char data = pop();		
		printf("%c %c\n",str[i],data);
		if(str[i]!=data)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int main()
{
	char str[50];
	printf("Enter the string\n");
	scanf("%s",str);
	if(check_palindrome(str,strlen(str)))
	{
		printf("Palindrome\n");
	}
	else
	{
		printf("No\n");
	}
	
}
