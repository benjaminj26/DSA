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
	if(top == 0 && stack[top] != '(')
	{
		printf("%c", stack[top]);
		top--;
		return top;
	}
	else if(stack[top] == '(')
	{
		top--;
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
	int size;
	char *expression = (char*)calloc(buffer,1);
	printf("Enter the expression:\n");
	getline(&expression, &buffer, stdin);
	size = strlen(expression);
	expression[size-1] = '\0';
	char stack[size/2+1];
	int top = -1;
	for(int i=0; i<size; ++i)
	{
		char ch = expression[i];
		int prty = priority(ch);
		if(prty >= 0)
		{
			if(prty > priority(stack[top]) || top == -1 || ch == '(')
				top = push(ch,stack,top);
			else if(prty <= priority(stack[top]))
			{
				if(ch == ')')
				{
					while(stack[top] != '(')
					{
						top = pop(stack,top);
					}
					top = pop(stack,top);
				}
				else
				{
					while(prty <= priority(stack[top]))
					{
						top = pop(stack,top);
						if(top == -1)
							break;
					}
					top = push(ch,stack,top);
				}
			}
		}
		else if(prty == -1)
		{
			printf("%c",ch);
		}
		if(i == size-1)
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
