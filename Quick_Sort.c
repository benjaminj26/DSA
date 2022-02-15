#include <stdio.h>

int partition(int array[], int low, int upp)
{
    int start = low+1;
    int end = upp;
    int pivot = array[low];
    
    while(array[start] <= pivot && start < end)
    {
        start++;
    }
    
    while (array[end] > pivot) 
    {
        end--;    
    }

    if(start < end)
    {
        int tmp = array[start];
        array[start] = array[end];
        array[end] = tmp;
    }

    else
    {
        int tmp = array[low];
        array[low] = array[end];
        array[end] = tmp;
    }

    return end;
}

void quick_sort(int array[], int low, int upp)
{
    if(low < upp)
    {
        int location = partition(array, low, upp);
        quick_sort(array, low, location-1);
        quick_sort(array, location+1, upp);
    }
}

void display(int array[], int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int array[size];

    printf("Enter %d elements:\n", size);
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &array[i]);
    }

    quick_sort(array, 0, size-1);

    printf("\nThe sorted array is:\n");
    display(array, size);
    return 0;
}