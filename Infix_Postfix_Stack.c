#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int priority(char ch)
{
	if(ch == '(' || ch == ')')
		return 0;
	else if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '^')
		return 3;
	else 
		return -1; 
}

int push(char ch, char *stack, int top)
{
	if(top == -1)
	{
		top = 0;
		stack[top] = ch;
		return top;
	}
	else
	{
		stack[++top] = ch;
		return top;
	}
}

int pop(char *stack, int top)
{
	if(top == 0)
	{
		printf("%c", stack[top]);
		top = -1;
		return top;
	}
	else 
	{
		printf("%c",stack[top]);
		top--;
		return top;
	}
}

int main()
{
	size_t buffer = 10;
	int size = 0;
	char *expression = (char*)calloc(buffer,1);
	printf("Enter the expression:\n");
	getline(&expression, &buffer, stdin);
	expression[strlen(expression)-1] = '\0';
	for(int i=0; i<strlen(expression); ++i)
	{
		if(expression[i] == '*')
			size++;
		else if(expression[i] == '/')
			size++; 
		else if(expression[i] == '+')
			size++;
		else if(expression[i] == '-')
			size++;
		else if(expression[i] == '^')
			size++;
	}
	char stack[size];
	int top = -1;
	for(int i=0; i<strlen(expression); ++i)
	{
		char ch = expression[i];
		int prty = priority(ch);
		if(prty >= 0)
		{
			if(prty > priority(stack[top]) || stack[top] == '\0')
				top = push(ch,stack,top);
			else if(prty <= priority(stack[top]))
			{
				if(ch == ')')
				{
					while(stack[top] != '(')
					{
						top = pop(stack,top);
					}
				}
				else
				{
					while(prty <= priority(stack[top]))
					{
						top = pop(stack,top);
					}
					top = push(ch,stack,top);
				}
			}
		}
		else if(prty == -1)
		{
			printf("%c",ch);
		}
		if(i == strlen(expression)-1)
		{
			while(top >= 0)
			{
				top = pop(stack,top);
			}
		}
	}
	printf("\n");
	free(expression);
	return 0;
}
