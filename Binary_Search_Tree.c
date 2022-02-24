#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int num)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, int number)
{
    if(*root == NULL)
    {
        struct node *new_node = create_node(number);
        *root = new_node;
    }
    else if(number <= (*root)->data)
    {
        insert_node(&(*root)->left, number);
    }
    else if(number > (*root)->data)
    {
        insert_node(&(*root)->right, number);
    }
}

struct node* traverse(struct node *root, int number)
{
    if(root->data == number)
    {
        return root;
    }
    traverse(root->left,number);
    traverse(root->right, number);
    return NULL;
}

void delete_node(struct node **root, int number)
{
    struct node *temp = traverse(*root, number);
    if(temp == NULL)
    {
        printf("\nElement not found\n");
    }
    else
    {
        struct node *swaper = *root;
        while(swaper->left != NULL)
        {
            swaper = swaper->left;
        }
        
    }
}

void display_tree(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        display_tree(root->left);
        printf("%d ", root->data);
        display_tree(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, number;
    do
    {
        printf
        (
            "1.Insert\n"
            "2.Delete\n"
            "3.Display\n"
            "4.Exit\nEnter your choice: "
        );
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("\nEnter the number: ");
                scanf("%d", &number);
                insert_node(&root, number);
                break;
            
            case 2:
                if(root == NULL)
                {
                    printf("\nThe List is Empty\n");
                }
                else 
                {
                    
                }

            case 3:
                if(root == NULL)
                {
                    printf("\nThe List is Empty\n");
                }
                else
                {
                    display_tree(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nINVALID INPUT\n");
        }
        printf("\n");
    }while(1);
}