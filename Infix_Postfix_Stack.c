#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int priority(char ch)
{
	if(ch == '(' || ch == ')')
		return 0;
	else if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
}

void push(char ch, char **stack)
{
	
}

void pop(char ch, char **stack)
{
	
}

void main()
{
	size_t buffer = 10;
	char *expression = (char*)calloc(buffer,1);
	printf("Enter the expression:\n");
	getline(&expression, &buffer, stdin);
	char *stack = (char*)malloc(1);
	for(int i=0; i<strlen(expression); ++i)
	{
		char ch = expression[i];
		int prty = priority(ch);
		if(prty > 0)
		{
			push(ch,&stack);
		}
		else if(isalnum(ch))
		{
			printf("%c",ch);
		}
	}
	return 0;
}
