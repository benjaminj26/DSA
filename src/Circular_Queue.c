#include<stdio.h>
#include<stdlib.h>

void display(int front, int rear, int size,int queue[])
{
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is Empty\n");
	}
	else if(rear >= front)
	{
		for(int i=front; i<=rear; ++i)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = front; i<size; ++i)
		{
			printf("%d ",queue[i]);
		}
		for(int i = 0; i<=rear; ++i)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}

void Enqueue(int *front, int *rear, int size, int queue[])
{
	if(*rear == size-1 && *front == 0 || *rear == *front-1)
	{
		printf("\nQueue is Full!!\n");
	}
	else if(*front == -1 && *rear == -1)
	{
		printf("\nEnter the element: ");
		*front = *rear = 0;
		scanf("%d", &queue[*rear]);
	}
	else if(*rear == size-1 && *front > 0)
	{
		*rear = 0;
		printf("\nEnter the element: ");
		scanf("%d", &queue[*rear]);
	}
	else
	{
		printf("\nEnter the element: ");
		(*rear)++;
		scanf("%d", &queue[*rear]);
	}
}

void Dequeue(int *front, int *rear, int size, int queue[])
{
	if(*front == -1)
	{
		printf("\nThe Queue is Empty!!\n");
	}
	else if(*front == *rear)
	{
		printf("\n%d is Deleted\n", queue[*front]);
		*front = *rear = -1;
	}
	else if(*front == size-1)
	{
		printf("\n%d is Deleted\n", queue[*front]);
		*front = 0;
	}
	else
	{
		printf("\n%d is Deleted\n", queue[*front]);
		(*front)++;
	}
}

int main()
{
	int front, rear, size;
	front = rear = -1;
	printf("Enter the size of the Queue: ");
	scanf("%d", &size);
	int queue[size];
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	do
	{
		printf("Enter your choice: ");
		int option;
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				Enqueue(&front, &rear, size, queue);
				break;
			case 2: 
				Dequeue(&front, &rear, size, queue);
				break;
			case 3:
				display(front, rear, size, queue);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Input!!\n");
		}
		printf("\n");
	}while(1);
}
