/*
	Program to implement Binary Search algorithm in C
	Author : Benjamin Joseph
	Date : 8-12-2021
*/

#include<stdio.h>

int main()
{
	int size;
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter %d elements:\n",size);
	for(int i=0; i<size; ++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Enter the element to be searched: ");
	int search;
	scanf("%d",&search);
	int mid = size/2;
	int flag = 0;
	int low = 0;
	int upp = size-1;
	while(mid>=0 && mid<size)
	{
		if(search == arr[mid])
		{
			printf("Element found at location %d\n",mid);
			flag = 1;
			break;
		}
		else if(search < arr[mid])
		{
			upp = mid;
			if((upp - low)/2 == 0)
			{
				mid -= 1;
			}
			mid = low + (upp - low)/2;
		}
		else if(search > arr[mid])
		{
			low = mid;
			if((upp - low)/2 == 0)
			{
				mid += 1;
			}
			else
			{
				mid = low + (upp - low)/2;
			}
		}
	}
	if(flag == 0)
	{
		printf("\nElement not Found\n");
	}
	return 0;
}
