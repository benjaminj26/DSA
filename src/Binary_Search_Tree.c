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
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == number)
    {
        return root;
    }
    else if(number <= root->data)
    {
        root = get_location(root->left, number);
    }
    else 
    {
        root = get_location(root->right, number);    
    }
    return root;
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
    largest = get_largest_element(root->right, largest);
    largest = get_largest_element(root->left, largest);
    return largest;
}

struct node* get_smallest_element(struct node *root, struct node *smallest)
{
    if(root == NULL)
    {
        return smallest;
    }
    if(smallest == NULL)
    {
        smallest = root;
    }
    else if(smallest->data >= root->data)
    {
        smallest = root;
    }
    smallest = get_smallest_element(root->left, smallest);   
    smallest = get_smallest_element(root->right, smallest);
    return smallest;
}

void replacer(struct node *temp1, struct node *temp2)
{
    struct node *temp3 = create_node(temp1->data);
    temp3->left = temp2->left;
    temp3->right = temp2->right;
    temp3->previous = temp2->previous;
    if(temp1->left == temp2)
    {
        temp2->left = temp1;
        temp2->right = temp1->right;
        temp1->left = temp3->left;
        temp1->right = temp3->right;
        if(temp2->right != NULL)
            (temp2->right)->previous = temp2;
        if(temp1->left != NULL)
            (temp1->left)->previous = temp1;
        if(temp1->right != NULL)
            (temp1->right)->previous = temp1;
        if(temp1->previous != NULL)
        {
            if((temp1->previous)->left == temp1)
            {
                (temp1->previous)->left = temp2;
            }
            else if((temp1->previous)->right == temp1)
            {
                (temp1->previous)->right = temp2;
            }
        }
        temp2->previous = temp1->previous;
        temp1->previous = temp2;
    }
    else if(temp1->right == temp2)
    {
        temp2->right = temp1;
        temp2->left = temp1->left;
        temp1->right = temp3->right;
        temp1->left = temp3->left;
        if(temp2->left != NULL)
            (temp2->left)->previous = temp2;
        if(temp1->left != NULL)
            (temp1->left)->previous = temp1;
        if(temp1->right != NULL)
            (temp1->right)->previous = temp1;
        if(temp1->previous != NULL)
        {
            if((temp1->previous)->left == temp1)
            {
                (temp1->previous)->left = temp2;
            }
            else if((temp1->previous)->right == temp1)
            {
                (temp1->previous)->right = temp2;
            }
        }
        temp2->previous = temp1->previous;
        temp1->previous = temp2;
    }
    else
    {
        temp2->left = temp1->left;
        temp2->right = temp1->right;
        temp1->left = temp3->left;
        temp1->right = temp3->right;
        if(temp2->left != NULL)
            (temp2->left)->previous = temp2;
        if(temp2->right != NULL)
            (temp2->right)->previous = temp2;
        if(temp1->left != NULL)
            (temp1->left)->previous = temp1;
        if(temp1->right != NULL)
            (temp1->right)->previous = temp1;

        //Changing the previous elements of the nodes
        if(temp1->previous != NULL)
        {    
            if((temp1->previous)->left == temp1)
            {
                (temp1->previous)->left = temp2;
            }
            else if((temp1->previous)->right == temp1)
            {
                (temp1->previous)->right = temp2;
            }
        }
        if((temp2->previous)->left == temp2)
        {
            (temp2->previous)->left = temp1;
        }
        else
        {
            (temp2->previous)->right = temp1;
        }
        temp2->previous = temp1->previous;
        temp1->previous = temp3->previous;
    }
    free(temp3);
}

void delete_node(struct node **root, int number)
{
    struct node *temp1 = get_location(*root, number);
    if(temp1 == NULL)
    {
        printf("\nElement not found\n");
        return;
    }
    struct node *temp2 = get_largest_element(temp1->left, NULL);
    if(temp2 == NULL)
        temp2 = get_smallest_element(temp1->right, NULL);
    if(temp2 == NULL)
    {
        if(temp1->previous != NULL)
        {    
            if((temp1->previous)->left == temp1)
            {
                (temp1->previous)->left = NULL;
            }
            else 
            {
                (temp1->previous)->right = NULL;
            }
        }
        if(*root == temp1)
        {
            *root = NULL;
        }
        free(temp1);
    }
    else if(temp2->left == NULL && temp2->right == NULL)
    {
        replacer(temp1, temp2);
        if((temp1->previous)->left == temp1)
        {
            (temp1->previous)->left = NULL;
        }
        else 
        {
            (temp1->previous)->right = NULL;
        }
        if(*root == temp1)
        {
            *root = temp2;
        }
        free(temp1);
    }
    else 
    {
        while(temp2->left != NULL || temp2->right != NULL)
        {
            struct node *new_temp1 = get_largest_element(temp2->left, NULL);
            if(new_temp1 == NULL)
                new_temp1 = get_smallest_element(temp2->right, NULL);
            replacer(temp2, new_temp1);
        }
        replacer(temp1, temp2);
        if((temp1->previous)->left == temp1)
        {
            (temp1->previous)->left = NULL;
        }
        else 
        {
            (temp1->previous)->right = NULL;
        }
        if(*root == temp1)
        {
            *root = temp2;
        }
        free(temp1);
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
                    if(root->data == number && root->left == NULL && root->right == NULL)
                    {
                        free(root);
                        root = NULL;
                    }
                    else
                        delete_node(&root, number);
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