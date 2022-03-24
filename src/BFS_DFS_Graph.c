/*
    C-Program to implement BFS and DFS for Graph Data Structure
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rear, front, size;
int *array = NULL;
int **adjacency_matrix = NULL;


void enqueue(int *queue, int element)
{
    if(rear == size-1)
        return;
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = queue[rear] = element;
    }
    else
    {
        queue[++rear] = element;
    }
}

int dequeue(int *queue)
{
    if(front > rear || (front == -1 && rear == -1))
        return 0;
    else
    {
        return queue[front++];
    }
}

void bfs(int *queue, int *visited)
{
    int index;
    int number = dequeue(queue);
    if(number == 0)
        return;
    else
    {
        printf("%d ", number);
        for(int i=0; i<size; ++i)
        {
            if(array[i] == number)
            {
                index = i;
            }
        }
        for(int i=0; i<size; ++i)
        {
            if(adjacency_matrix[index][i] == 1)
            {
                if(visited[i] == 0)
                {
                    enqueue(queue, array[i]);
                    visited[i] = 1;
                }
            }
        }
        bfs(queue, visited);
    }
}

void dfs(int *stack, int *visited, int index)
{   
    printf("%d ", array[index]);
    visited[index] = 1;
    for(int i=0; i<size; ++i)
    {
        if(adjacency_matrix[index][i] == 1)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                dfs(stack, visited, i);
            }
        }
    }
    
}

void print_adjacency_matrix()
{
     printf("The adjacency matrix is\n");
    //Printing the rows and columns
    for(int i=0; i<size; ++i)
    {
        printf("\t%d", array[i]);
    }
    printf("\n");
    //Printing the adjacency matrix
    for(int i=0; i<size; ++i)
    {
        printf("%d",array[i]);
        for(int j=0; j<size; ++j)
        {
            printf("\t%d", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void create_adjacency_matrix()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    array = (int *)calloc(size, sizeof(int));
    printf("Enter %d elements\n", size);
    int number;
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &number);
        array[i] = number;
    }
    adjacency_matrix = (int **)calloc(size, sizeof(int *));
    for(int i=0; i<size; ++i)
    {
        adjacency_matrix[i] = (int *)calloc(size, sizeof(int));
        for(int j=0; j<size; ++j)
        {
            printf("Enter 1 if %d has adjacency with %d: ", array[i], array[j]);
            scanf("%d", &number);
            adjacency_matrix[i][j] = number;
        }
    }
}

int main()
{
    create_adjacency_matrix();
    print_adjacency_matrix();
    printf("\n");
    int visited[size], index, option;
    int queue[size], stack[size];
    do 
    {
        printf
        (
            "1.Breadth First Search\n"
            "2.Depth First Search\n"
            "3.Print the adjacency matrix\n"
            "4.Re-define the graph\n"
            "5.Exit\n"
            "Enter your choice: "
        );
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                //Initializing all the elements of the visited array to 0
                front = rear = -1;
                memset(visited, 0, size*sizeof(int));
                printf("\nEnter the index of the root node: ");
                scanf("%d", &index);
                visited[index] = 1;
                printf("The BFS traversal of the graph is:\n");
                enqueue(queue, array[index]);
                bfs(queue, visited);
                break;

            case 2:
                //Initializing all the elements of the visited array to 0
                memset(visited, 0, size*sizeof(int));
                printf("\nEnter the index of the root node: ");
                scanf("%d", &index);
                printf("The DFS traversal of the graph is:\n");
                dfs(stack, visited, index);
                break;

            case 3:
                print_adjacency_matrix();
                break;

            case 4:
                free(array);
                for(int i=0; i<size; ++i)
                {
                    free(adjacency_matrix[i]);
                }
                free(adjacency_matrix);
                create_adjacency_matrix();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Input\n");
        }
        printf("\n\n");
    }while (1);
    return 0;
}
