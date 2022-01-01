#include<stdio.h>
#include <stdlib.h>

void display(int queue[], int rear, int front)
{
	for(int i=front; i<rear+1; ++i)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}

void enqueue(int size,int queue[],int *rear, int *front)
{
	if(rear == size-1)
		printf("\nQueue is full\n");
	else if(*rear == *front == -1)
	{
		*front = 0;
		printf("Input the number: ");
		scanf("%d", &queue[++(*rear)]);
	}
}

void dequeue(int size,int queue[],int *rear, int *front)
{
	if(*front == *rear+1)
	{
		printf("\nQueue is empty\n");
	}
	else if(*front == -1) 
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("\n%d is deleted\n", queue[(*front)++]);
	}
}

int main()
{
	int opt, size, front=-1, rear=-1;
	printf("Input the size of the queue: ");
	scanf("%d", &size);
	int queue[size];
	do
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nInput your choice: ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1: 
				enqueue(size, queue, &rear, &front);
				break;
			case 2: 
				dequeue(size, queue, &rear, &front);
				break;
			case 3: 
				display(queue,rear,front);
				break;
			case 4: 
				exit(0);
			default : printf("Invalid Input\n");
		}
	}while(1);
}
