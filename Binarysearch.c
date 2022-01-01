/*
	Program to implement Binary Search algorithm in C
	Author : Benjamin Joseph
	Date : 8-12-2021
*/

#include<stdio.h>

int main()
{
	int size, count=0, space=4;
	printf("Enter the number of elements: ");
	count++;
	scanf("%d",&size);
	count++;
	int arr[size];
	space+=size*4;
	printf("Enter %d elements:\n",size);
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		scanf("%d",&arr[i]);
		count++;
	}
	space+=4;
	printf("Enter the element to be searched: ");
	count++;
	int search;
	space+=4;
	scanf("%d",&search);
	count++;
	int mid=size/2;
	space+=4;
	count++;
	int flag = 0;
	space+=4;
	count++;
	while(mid>=0 && mid<size)
	{
		count++;
		if(search == arr[mid])
		{
			count++;
			printf("Element found at location %d\n",mid);
			count++;
			flag = 1;
			count++;
			break;
		}
		else if(search < arr[mid])
		{
			count++;
			mid-=mid/2;
			count++;
		}
		else if(search > arr[mid])
		{
			count++;
			mid+=mid/2;
			count++;
		}
	}
	printf("\nThe time complexity is: %d\n", count);
	printf("\nThe space complexity is: %d\n", space);
	return 0;
}
