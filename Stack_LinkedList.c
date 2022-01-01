/*
    Program to implement Stack as Linked List
    Author : Benjamin Joseph
    Date : 25-12-2021
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Employee
{
    unsigned int empid;
    char *name;
    char *address;
    char *department;
    struct Employee *next;
};

//Function to display the details of an employee
void display_emp(struct Employee *top)
{
    if(top == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nEmployee ID: %u\n", top->empid);
        printf("Name: %s", top->name);
        printf("Address: %s", top->address);
        printf("Department: %s", top->department);
    }
}

//Function to create a variable of type struct Employee on the heap
void create_emp(struct Employee **e)
{
    size_t buff_size = 10;
    *e = (struct Employee*)malloc(sizeof(struct Employee));
    (*e)->name = (char*)calloc(buff_size,sizeof(char));
    (*e)->address = (char*)calloc(buff_size,sizeof(char));
    (*e)->department = (char*)calloc(buff_size,sizeof(char));
}

//Function to push a node onto the stack
void push(struct Employee **top)
{
    size_t buff_size = 10;
    struct Employee *e;
    create_emp(&e);
    printf("Enter the Employee ID of the Employee: ");
    scanf("%u", &e->empid);
    getchar();
    printf("Enter the name of the Employee: ");
    getline(&e->name,&buff_size,stdin);
    printf("Enter the address of the Employee: ");
    buff_size = 10;
    getline(&e->address,&buff_size,stdin);
    printf("Enter the department of the Employee: ");
    buff_size = 10;
    getline(&e->department,&buff_size,stdin);
    if (*top == NULL)
    {
        e->next = NULL;
        *top = e;
    }
    else
    {
        e->next = *top;
        *top = e;
    }
}

//Function to pop a node from the stack
void pop(struct Employee **top)
{
    if(*top != NULL)
    {
        struct Employee *e = *top;
        *top = (*top)->next;
        printf("\nThe details of the following employee are deleted\n");
        display_emp(e);
        printf("\n");
        free(e->name);
        free(e->address);
        free(e->department);
        e->next = NULL;
        free(e);
    }
    else
    {
        printf("\nStack is Empty\n");
    }
}

int main()
{
    int option;
    struct Employee *top = NULL;
    do
    {
        printf("1.Push\n2.Pop\n3.Display Top Element\n4.Clear\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display_emp(top);
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
