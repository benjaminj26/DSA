#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int low, int mid, int upp)
{
    int i,j,k;
    int leftsize = mid-low+1;
    int left_array[leftsize];
    int rightsize = upp-mid;
    int right_array[rightsize];

    for(i=0, k=low; i<leftsize; ++i,++k)
    {
        left_array[i] = array[k];
    }

    for(j=0, k=mid+1; j<rightsize; ++j,++k)
    {
        right_array[j] = array[k];
    }

    i = 0;
    j = 0;
    k = low;

    while(i<leftsize && j<rightsize)
    {
        if(left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while(i<leftsize)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }
    while(j<rightsize)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int low, int upp)
{
    if(low < upp)
    {
        int mid = low + (upp - low)/2;
        merge_sort(array, low, mid);
        merge_sort(array, mid+1, upp);
        merge(array, low, mid, upp);
    }
}

void print_array(int array[], int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {90,89, 67, 53, 43};
    int size = sizeof(array)/sizeof(int);
    merge_sort(array, 0, size-1);
    print_array(array, size);
    return 0;
}