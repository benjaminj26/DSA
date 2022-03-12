/*
    Program to implement Queue as linked list
    Author : Benjamin Joseph
    Date : 29-12-2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    unsigned int empid;
    char *name;
    char *address;
    char *department;
    struct Employee *next;
};

void Employee_Display(struct Employee *e)
{
    if(e == NULL)
    {
        printf("\nThe Queue is Empty\n");
    }
    else
    {
        printf("Employee Id: %d\n", e->empid);
        printf("Name: %s", e->name);
        printf("Address: %s", e->address);
        printf("Department: %s", e->department);
    }
}

void Employee_Init(struct Employee **e)
{
    *e = (struct Employee*)malloc(sizeof(struct Employee));
    (*e)->name = (char*)calloc(1,1);
    (*e)->address = (char*)calloc(1,1);
    (*e)->department = (char*)calloc(1,1);
}

void Enqueue(struct Employee **rear, struct Employee **front)
{
    struct Employee *e;
    Employee_Init(&e);
    printf("\nEnter the Employee Id: ");
    scanf("%d",&e->empid);
    getchar();
    printf("Enter the name: ");
    size_t buffer = 10;
    getline(&e->name, &buffer, stdin);
    printf("Enter the address: ");
    buffer = 10;
    getline(&e->address, &buffer, stdin);
    printf("Enter the department: ");
    buffer = 10;
    getline(&e->department, &buffer, stdin);
    e->next = NULL;
    if(*rear == NULL && *front == NULL)
    {
        *rear = *front = e;
    }
    else
    {
        (*rear)->next = e;
        *rear = e;
    }
}

void Dequeue(struct Employee **front)
{
    if(*front == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nThe details of the following Employee are deleted\n");
        Employee_Display(*front);
        struct Employee *e = *front;
        *front = (*front)->next;
        free(e->name);
        free(e->address);
        free(e->department);
        free(e);
    }
}

int main()
{
    struct Employee *front = NULL, *rear = NULL;
    int option;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display Front Element\n4.Clear the screen\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                Enqueue(&rear, &front);
                break;
            case 2:
                Dequeue(&front);
                break;
            case 3:
                Employee_Display(front);
                break;
            case 4:
                system("clear");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Input\n");
        }
        printf("\n");
    }while(1);
}
