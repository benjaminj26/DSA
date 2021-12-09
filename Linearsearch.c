#include<stdio.h>

int main()
{
	int size,count=0;
	printf("Input the number of elements: ");\
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
	int num,flag=0;
	count++;
	printf("Input the number to be searched: ");
	count++;
	scanf("%d",&num);
	count++;
	for(int i=0; i<size; ++i)
	{
		count++;
		if(arr[i] == num)
		{
			count++;
			flag = 1;
			count++;
			printf("Element found at location %d\n",i);
			count++;
			break;
		}
	}
	if(flag == 0)
	{
		count++;
		printf("Element not found!!\n");
		count++;
	}
	printf("\nThe time complexity is %d\n",count);
	return 0;
}
