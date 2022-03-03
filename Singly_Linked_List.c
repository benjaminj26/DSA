#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *end = NULL;

struct node* create_node(int number)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = number;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning()
{
    int number;
    printf("Enter the value of the new node: ");
    scanf("%d", &number);
    struct node *new_node = create_node(number);
    if(start == NULL)
    {
        start = new_node;
        end = new_node;
    }
    else
    {
        new_node->next = start;
        start = new_node;
    }
}

void insert_at_end()
{
    int number;
    printf("Enter the value of the new node: ");
    scanf("%d", &number);
    struct node *new_node = create_node(number);
    if(end == NULL)
    {
        start = new_node;
        end = new_node;
    }
    else
    {
        end->next = new_node;
        end = new_node;
    }
}

void insert_at_position()
{
    struct node *temp = start;
    if(temp == NULL)
    {
        insert_at_beginning();
    }
    else
    {
        int element;
        printf("Enter the value of the element in front of which you want to insert: ");
        scanf("%d", &element);
        int flag=0;
        while(temp != NULL)
        {
            if((temp)->data == element)
            {
                flag++;
                printf("Enter the value of new node: ");
                int number;
                scanf("%d", &number);
                struct node *new_node = create_node(number);
                new_node->next = temp->next;
                temp->next = new_node; 
                break;
            }
           temp = temp->next; 
        }
        if(flag == 0)
        {
            printf("\nElement not found\n");
        }
    }
}

void delete_at_beginning()
{
    if(start == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

void delete_at_end()
{
    if(start == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    struct node *temp = start;
    while(temp->next != end)
    {
       temp = temp->next; 
    }
    end = temp;
    end->next = NULL;
    free(temp->next);
}

void delete_at_position()
{
    if(start == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    int element;
    printf("Enter the value of the element which you want to delete: ");
    scanf("%d", &element);
    struct node *temp = start;
    while(temp != NULL)
    {
        if(start->data == element)
        {
            delete_at_beginning();
            break;
        }
        else if(end->data == element)
        {
            delete_at_end();
            break;
        }
        else if((temp->next)->data == element)
        {
            struct node *trash = temp->next;
            temp->next = (temp->next)->next;
            free(trash);
            break;
        }
        temp = temp->next;
    }
}

void display_elements()
{
    if(start == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    printf("\n");
    struct node *temp = start;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf
    (
        "1.Insert at the beginning\n"
        "2.Insert at the end\n"
        "3.Insert in front of a node\n"
        "4.Delete at the beginning\n"
        "5.Delete at the end\n"
        "6.Delete node at a position\n"
        "7.Display the elements\n"
        "8.Exit\n"
    );
    do
    {
        printf("Enter your choice: ");
        int option;
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_position();
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                delete_at_position();
                break;
            case 7:
                display_elements();
                break;
            case 8: 
                exit(0);
            default:
                printf("\nInvalid Input\n");
        }
        printf("\n");
    }while (1);
}