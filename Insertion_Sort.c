#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int array[size];
    printf("Enter %d elements:\n", size);
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &array[i]);
    }
    for(int i=1; i<size; ++i)
    {
        int key = array[i];
        for(int j=i-1; j>=0; --j)
        {
            if(key < array[j])
            {
                int tmp = array[j];
                array[j] = key;
                array[j+1] = tmp;
            }
        }
    }
    printf("\nThe sorted array is:\n");
    for(int i=0; i<size; ++i)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");
    return 0;
}