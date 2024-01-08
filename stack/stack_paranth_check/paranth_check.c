 /*
*Name: Yogesh
*Date: 8/1/24
*program: C program to Check for balanced Parentheses in an Expression using Stack
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
	char data;
	struct Stack *link;
};

struct Stack *sPtr = NULL;

void push(char data)
{
	struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
	temp->data = data;
	temp->link = NULL;
	if(sPtr==NULL)
	{
		sPtr = temp;
	}
	else
	{
		temp->link = sPtr;
		sPtr = temp;		
	}
}
char pop()
{
		struct Stack *temp = sPtr;
		char res = sPtr->data;
		sPtr = sPtr->link;
		free(temp);
		return res;
}
/*void print()
{
	struct Stack *temp = sPtr;
	while(temp)
	{
		printf("%c\n",temp->data);
		temp = temp->link;
	}
}*/

int match_pair(char data_1,char data_2)
{
	printf("%c %c",data_1,data_2);
	if(data_1=='('&&data_2==')')
	{
		return 1;
	}
	if(data_1=='['&&data_2==']')
	{
		return 1;
	}
	if(data_1=='{'&&data_2=='}')
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int paranth_check(char *str, int len)
{
	int i;
	while(str[i])
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			push(str[i]);
		}
		if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			char data = pop();
			if(!match_pair(data,str[i]))
			{
				return 0;
			}
		}
		i++;	
		
	}	
	if(sPtr==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	char str[50];
	scanf("%s",str);
	if(paranth_check(str,strlen(str)))
	{
		printf("Equal\n");
	}
	else
	{
		printf("Not equal\n");
	}
	
}
