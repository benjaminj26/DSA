#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const int size = 50;
    int tree[size];
    for(int i=0; i<size; ++i)
    {
        tree[i] = -1;
    }
    do
    {
        printf
        (
            "1.Insert a number\n"
            "2.Delete a number\n"
            "3.Display the tree\n"
            "4.Exit\n"
            "Enter your choice: "    
        );
        int choice;
        int number;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                if(tree[1] == -1)
                {
                    printf("\nEnter the value of root element: ");
                    scanf("%d",&number);    
                    tree[1] = number;
                }
                else
                {
                    printf("\nEnter the index of the parent node: ");
                    int index;
                    scanf("%d", &index);
                    if(tree[index] != -1)
                    {
                        printf("Enter the number: ");
                        scanf("%d",&number);
                        printf("\n1.Left Node\n2.Right Node\nWhere do you want to insert the element?: ");
                        int opt;
                        scanf("%d", &opt);
                        if(opt == 1)
                        {
                            if(tree[index*2] == -1)
                                tree[index*2] = number;
                            else
                                printf("Index is already occupied\n");
                        }
                        else if(opt == 2)
                        {
                            if(tree[index*2+1] == -1)
                                tree[index*2+1] = number;
                            else
                                printf("\nIndex is already occupied\n");
                        }
                        else
                            printf("\nInvalid Input\n");
                    }
                    else 
                    {
                        printf("\nThe index of parent node specified is empty\n");
                    }
                }
                break;

            case 2:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &number);
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] == number)
                    {
                        if(tree[i*2] && tree[i*2+1] == -1)
                        {
                            tree[i] = -1;
                        }
                        else
                        {
                            printf("\nThe index specified is not a leaf node and thus cannot be deleted\n");
                        }
                        break;
                    }
                }
                break;

            case 3:
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] != -1)
                        printf("%d ",i);
                }
                printf("\n");
                break;

            case 4:
                exit(0);
        }

    }while (1);
    return 0;
}