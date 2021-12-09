#include<stdio.h>

int main()
{
	int size, min_index, count=0;
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
	count++;
	for(int i=0; i<size-1; ++i)
	{
		count++;
		min_index = i;
		count++;
		for(int j=i+1; j<size; ++j)
		{
			count++;
			if(arr[j]<arr[min_index])
			{	
				count++;
				min_index=j;
				count++;
			}	
		}
		count++;
		int tmp = arr[min_index];
		count++;
		arr[min_index] = arr[i];
		count++;
		arr[i] = tmp;
		count++;
	}
	count++;
	printf("\nThe sorted array is:\n");
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		printf("%d ",arr[i]);
		count++;
	}
	printf("\nThe Time Complexity is %d\n",count);
	return 0;
}
