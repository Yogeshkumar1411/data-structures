 /*
*Name: Yogesh
*Date: 8/1/24
*program: C Program to Check String is Palindrome using Stack
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *stack;
int sPtr = 0;

void push(char data)
{
	stack[sPtr++] = data;
}

char pop()
{
	return stack[sPtr--];
}

int check_palindrome(char *str,int len)
{
	stack = (char*)malloc(len*sizeof(char));
	int i;
	for(i=0;i<len;i++)
	{
		push(str[i]);
	}
	i=0;
	sPtr--;
	while(sPtr>=0)
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
