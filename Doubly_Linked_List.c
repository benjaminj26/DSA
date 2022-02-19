#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void display()
{
    if(head == NULL && tail == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        printf("\n");
        struct node *tmp = head;
        while(tmp != NULL)
        {
            printf("%d ",tmp->data);
            tmp = tmp->next;
        }
    }
    printf("\n");
}

void add_element()
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value of the element: ");
    int data;
    scanf("%d", &data);
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head == NULL && tail == NULL)
    {
        head = tail = new_node;
    }
    else 
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void delete_element()
{
    if(head == NULL && tail == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {   
        int element;
        printf("Enter the value of the element to be deleted: ");
        scanf("%d", &element);
        struct node *tmp = head;
        int flag = 0;
        while(tmp != NULL)
        {
            if(head == NULL && tail == NULL)
            {
                printf("\nThe list is empty\n");
            }
            else if(tmp->data == element)
            {
                if(tmp == head && tmp == tail)
                {
                    printf("\nElement deleted successfully\n");
                    free(head);
                    head = tail = NULL;
                    flag++;
                    break;
                }
                else if(tmp == tail)
                {
                    printf("\nElement deleted successfully\n");
                    tail = tmp->prev;
                    (tmp->prev)->next = NULL;
                    free(tmp);
                    flag++;
                    break;    
                }
                else if(tmp == head)
                {
                    printf("\nElement deleted successfully\n");
                    head = tmp->next;
                    (tmp->next)->prev = NULL;
                    free(tmp);
                    flag++;
                    break;
                }
                else
                {
                    printf("\nElement deleted successfully\n");
                    (tmp->prev)->next = tmp->next;
                    (tmp->next)->prev = tmp->prev;
                    free(tmp);
                    flag++;
                    break;
                }
            }
            else
            tmp = tmp->next;
        }
        if(flag == 0)
        {
            printf("\nElement not found\n");
        }
    }
}

void free_all()
{
    while(head != NULL)
    {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    printf
    (
        "1.Input new element\n"
        "2.Delete element\n"
        "3.Display all elements\n"
        "4.Exit\nEnter your choice: "
    );
    do
    {
        int opt;
        scanf("%d", &opt);
        switch (opt) 
        {
            case 1:
                add_element();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Input\n");
        }
        printf("\n");
    }while(1);
    return 0;
}