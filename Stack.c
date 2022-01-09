/*
	C program to implement Stack data structure
	Author : Benjamin Joseph
	Date : 14-12-2021
*/

#include<stdio.h>

void display(int *arr,int top)
{
	for(int i=0; i<top+1; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

void push(int size, int *arr, int *top)
{
	if(*top == size-1)
		printf("\nStack Overflow\n");
	else
	{
		printf("\nInput the element: ");
		scanf("%d", &arr[++(*top)]);
		printf("\nStack after insertion is:\n");
		display(arr,*top);
	}
}

void pop(int size, int *arr, int *top)
{
	if(*top == -1)
		printf("\nStack Underflow\n");
	else
	{
		printf("\n%d has been deleted\n",arr[(*top)--]);
		printf("The stack after deletion is:\n");
		display(arr,*top);
	}

}

void peek(int *arr, int *top)
{
	printf("\nElement at the top is %d\n", arr[*top]);
}

int main()
{
	int size;
	printf("Input the size of the stack: ");
	scanf("%d", &size);
	int top=-1;
	int arr[size], opt;
	do
	{
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
			 	push(size,arr,&top);
				break;
			case 2:
				pop(size,arr,&top);
				break;
			case 3:
				peek(arr, &top);
				break;
			case 4:
				display(arr,top);
				break;
			case 5:
				return 0;
			default:
				printf("Invalid Input\n");
		}
	}while(1);
}
