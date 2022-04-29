#include<stdio.h>
#include<stdlib.h>

void swap(int *heap, int index1, int index2)
{
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void heapify(int *heap, int size, int index)
{
    int largest = index;
	int left = index * 2 + 1;
	int right = index * 2 + 2;

	if(left < size && heap[left] > heap[largest])
	{
		largest = left;
	}

	if(right < size && heap[right] > heap[largest])
	{
		largest = right;
	}

	if(index != largest)
	{
		swap(heap, largest, index);
		heapify(heap, size, largest);
	}
}

void heap_sort(int *heap, int size)
{
   for(int i=(size/2)-1; i >= 0; --i)
   {
	   heapify(heap, size, i);
   }

   for(int i=size-1; i >= 0; --i)
   {
	   swap(heap, 0, i);
	   heapify(heap, i, 0);
   }
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int heap[size];
    printf("\nEnter %d elements: ", size);
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &heap[i]);
    }
    heap_sort(heap,size);
    printf("\nThe sorted array is\n");
    for(int i=0; i<size; ++i)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}
