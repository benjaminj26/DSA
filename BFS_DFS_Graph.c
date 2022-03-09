#include<stdio.h>
#include<string.h>

int top=-1, rear=-1, front=-1;

void push(int *stack, int element)
{
    stack[++top] = element;
}

void pop(int *stack)
{
    printf("%d ", stack[top--]);
}

void enqueue(int *queue, int element)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = queue[rear] = element;
    }
    else
    {
        queue[++rear] = element;
    }
}

void dequeue(int *queue)
{
    printf("%d ", queue[front++]);
}

void bfs(int *array, int **adjacency_matrix)
{
    int size = sizeof(array)/4;
    int visited[size];
    memset(visited, 0, size);
    printf("Enter the index of the root node: ");
    int index;
    scanf("%d", &index);
    // printf("%d ", array[index]);
    visited[index] = 1;
    int queue[size];
    enqueue(queue, array[index]);
    for(int i=0; i<size; ++i)
    {
        if(adjacency_matrix[index][i] == 1)
        {
            dequeue(queue);
            if(visited[i] == 0)
            {
                enqueue(queue, array[i]);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int *array)
{

}

int main()
{
    printf("Enter the number of nodes: ");
    int size;
    scanf("%d", &size);
    int array[size];
    printf("Enter %d elements\n", size);
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &array[i]);
    }
    int adjacency_matrix[size][size];
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            printf("Enter 1 if %d has adjacency with %d: ", array[i], array[j]);
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
    printf("The adjacency matrix is\n");
    for(int i=0; i<size; ++i)
    {
        printf("\t%d", array[i]);
    }
    printf("\n");
    for(int i=0; i<size; ++i)
    {
        printf("%d",array[i]);
        for(int j=0; j<size; ++j)
        {
            printf("\t%d", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}