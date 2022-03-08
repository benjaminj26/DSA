#include<stdio.h>
#include<stdlib.h>

void swap(int *heap, int index1, int index2)
{
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void heapify(int *heap, int size)
{
    if(size <= 1)
        return;
    for(int i=size-1; i >= (size/2); i--)
    {
        if(i%2 == 0)
        {
            if(heap[i] > heap[(i/2)-1])
            {
                swap(heap, i, ((i/2)-1)); 
            }
        }
        else
        {
            if(heap[i] > heap[(i/2)])
            {
                swap(heap, i, (i/2));
            }
        }
    }
    heapify(heap, (size)/2);
}

void heap_sort(int *heap, int size)
{
    if(size <= 1)
        return;
    heapify(heap, size);
    swap(heap,0,size-1);
    heap_sort(heap, size-1);
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