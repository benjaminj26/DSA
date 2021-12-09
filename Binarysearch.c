#include<stdio.h>

int main()
{
	int size, count=0;
	printf("Input the number of elements: ");
	count++;
	scanf("%d",&size);
	count++;
	int arr[size];
	printf("Input %d elements:\n",size);
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		scanf("%d",&arr[i]);
		count++;
	}
	printf("The sorted array is:\n");
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		printf("%d ",arr[i]);
		count++;
	}
	printf("\n");
	count++;
	printf("Input the element to be searched: ");
	count++;
	int search;
	scanf("%d",&search);
	count++;
	int mid=size/2;
	count++;
	int flag = 0;
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
	printf("The time complexity is: %d\n", count);
	return 0;
}
