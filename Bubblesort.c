#include<stdio.h>

int main()
{
	int size,count=0;
	printf("Input the number of elements: ");
	count++;
	scanf("%d",&size);
	count++;
	int arr[size];
	printf("Input %d elements:\n",size);\
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		scanf("%d", &arr[i]);
		count++;
	}
	count++;
	for(int i=1; i<size; ++i)
	{
		count++;
		for(int j=0; j<size-i; ++j)
		{
			count++;
			if(arr[j] > arr[j+1])
			{
				count++;
				int tmp = arr[j];
				count++;
				arr[j] = arr[j+1];
				count++;
				arr[j+1] = tmp;
				count++;
			}
		}
		count++;
	}
	count++;
	printf("The sorted array is:\n");
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		printf("%d ",arr[i]);
		count++;
	}
	count++;
	printf("\nThe Time Complexity is %d\n",count);
	return 0;
}
