#include<stdio.h>

int main()
{
	int size, min_index, count=0, space=8;
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
	space+=8;
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
	printf("\nThe space Complexity is %d\n", space);
	return 0;
}
