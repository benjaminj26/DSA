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

void traverse(struct node *root, struct node *swaper, int number)
{
    if(root == NULL)
    {
        return;
    }
    if((root->left)->data == number || (root->right)->data == number)
    {
        swaper = root;
    }
    traverse(root->left, swaper, number);
    traverse(root->right, swaper, number);
}

void delete_node(struct node **root, int number)
{
    if((*root)->data == number)
    {
        struct node *swaper = *root;
        while((swaper->right)->left != NULL && (swaper->right)->right != NULL)
        {
            swaper = swaper->right;
        }
        (swaper->right)->left = (*root)->left;
        (swaper->right)->right = (*root)->right;
        struct node *temp = *root;
        *root = swaper->right;
        swaper->right = temp;
        free(swaper->right);
        swaper->right = NULL;
    }
    else
    {
        struct node *temp = NULL;
        traverse(*root, temp, number);
        if(temp == NULL)
        {
            printf("\nElement not found\n");
        }
        else
        {
            struct node *swaper = *root;
            if(swaper == NULL)
            {
                return;
            }
            while((swaper->right)->left != NULL || (swaper->right)->right != NULL)
            {
                if(swaper->right != NULL)
                    swaper = swaper->right;
                else
                    swaper = swaper->left;
            }
            if((temp->left)->data == number)
            {
                (swaper->right)->left = (temp->left)->left;
                (swaper->right)->right = (temp->left)->right;
                struct node *trash = temp->left;
                temp->left = swaper->right;
                swaper->right = trash;
                free(swaper->right);
                swaper->right = NULL;
            }
            else if((temp->right)->data == number)
            {
                (swaper->right)->left = (temp->right)->left;
                (swaper->right)->right = (temp->right)->right;
                struct node *trash = temp->right;
                temp->right = swaper->right;
                swaper->right = trash;
                free(swaper->right);
                swaper->right = NULL;
            }
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
                    printf("\nEnter the number to delete: ");
                    scanf("%d", &number);
                    delete_node(&root, number);
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