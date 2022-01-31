#include <stdio.h>
#include <stdlib.h>

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
            "4.Find the parent of a node\n"
            "5.Find the children of a node\n"
            "6.Find the index of a node\n"
            "7.Exit\n"
            "Enter your choice: "    
        );
        int choice;
        int number,flag;
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
                                printf("\nIndex is already occupied\n");
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
                flag=0;
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &number);
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] == number)
                    {
                        flag++;
                        if(tree[i*2] && tree[i*2+1] == -1)
                        {
                            tree[i] = -1;
                        }
                        else
                        {
                            for(int j=size/2-1; j>=1; --j)
                            {
                                if(tree[j*2+1] != -1)
                                {
                                    tree[i] = tree[j*2+1];
                                    tree[j*2+1] = -1;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                if(flag == 0)
                    printf("\nElement not found\n");
                break;

            case 3:
                printf("\n");
                for(int i=1; i<size; ++i)
                {
                    if(tree[1] == -1)
                        printf("\nThe tree is empty\n");
                    else if(tree[i] != -1)
                    {
                        printf("%d ",tree[i]);
                    }
                }
                printf("\n");
                break;

            case 4:
                flag=0;
                printf("\nEnter the element: ");
                scanf("%d", &number);
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] == number)
                    {
                        flag++;
                        printf("The parent of %d is %d\n", tree[i], tree[i/2]);
                    }
                }
                if(flag == 0)
                    printf("\nElement not found\n");
                break;

            case 5:
                flag=0;
                printf("\nEnter the element: ");
                scanf("%d",&number);
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] == number)
                    {
                        flag++;
                        if(tree[i*2] != -1 && tree[i*2+1] != -1)
                        {
                            printf("\nLeft child of %d is %d\n", tree[i], tree[i*2]);
                            printf("Right child of %d is %d\n", tree[i], tree[i*2+1]);
                        }
                        else if(tree[i*2] == -1 && tree[i*2+1] != -1)
                        {
                            printf("\nLeft child of %d is empty\n", tree[i]);
                            printf("Right child of %d is %d\n", tree[i], tree[i*2+1]);
                        }
                        else if(tree[i*2] != -1 && tree[i*2+1] == -1)
                        {
                            printf("\nLeft child of %d is %d\n", tree[i], tree[i*2]);
                            printf("Right child of %d is empty\n", tree[i]);
                        }
                        else 
                        {
                            printf("\nThe node has no children\n");
                        }
                    }
                }
                if(flag == 0)
                    printf("\nElement not found\n");
                break;

            case 6:
                flag=0;
                printf("\nEnter the element: ");
                scanf("%d", &number);
                for(int i=0; i<size; ++i)
                {
                    if(tree[i] == number)
                    {
                        flag++;
                        printf("The index of %d is %d\n", number, i);
                        break;
                    }
                }
                if(flag == 0)
                    printf("\nElement not found\n");
                break;

            case 7:
                exit(0);
            default:
                printf("\nInvalid Input\n");
        }
        printf("\n");

    }while (1);
    return 0;
}