#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *previous;
};

struct node* create_node(int num)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->previous = NULL;
    return new_node;
}

void insert_node(struct node **root, struct node *current, int number)
{
    if(*root == NULL)
    {
        struct node *new_node = create_node(number);
        if(new_node == NULL)
        {
            printf("\nUnable to create node\n");
            return;
        }
        new_node->previous = current;
        *root = new_node;
    }
    else if(number <= (*root)->data)
    {
        insert_node(&(*root)->left, *root, number);
    }
    else if(number > (*root)->data)
    {
        insert_node(&(*root)->right, *root, number);
    }
}

struct node* get_location(struct node *root, int number)
{
    if(root->data == number)
    {
        return root;
    }
    else if(number <= root->data)
    {
        get_location(root->left, number);
    }
    else 
    {
        get_location(root->right, number);    
    }
}

struct node* get_largest_element(struct node *root, struct node *largest)
{
    if(root == NULL)
    {
        return largest;
    }
    if(largest == NULL)
    {
        largest = root;
    }
    else if(largest->data <= root->data)
    {
        largest = root;
    }
    largest = get_largest_element(root->left, largest);
    largest = get_largest_element(root->right, largest);
    return largest;
}

void delete_node(struct node *root, int number)
{
    struct node *temp1 = get_location(root, number);
    struct node *temp2 = get_largest_element(temp1->left, NULL);
    struct node *trash = NULL;
    if(temp2->left == NULL && temp2->right == NULL)
    {
        temp2->left = temp1->left;
        temp2->right = temp1->right;
        trash = temp1;
        if((temp1->previous)->left == temp1)
        {
            (temp1->previous)->left = temp2;
            if((temp2->previous)->left == temp2)
            {
                (temp2->previous)->left = NULL;
            }
            else
            {
                (temp2->previous)->right = NULL;
            }
        }
        else 
        {
            (temp1->previous)->right = temp2;
            if((temp2->previous)->left == temp2)
            {
                (temp2->previous)->left = NULL;
            }
            else
            {
                (temp2->previous)->right = NULL;
            }
        }
        free(trash);
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
                insert_node(&root, NULL, number);
                break;
            
            case 2:
                if(root == NULL)
                {
                    printf("\nThe List is Empty\n");
                }
                else 
                {
                    printf("Enter the number to be deleted: ");
                    scanf("%d", &number);
                    delete_node(root, number);
                }
                break;

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