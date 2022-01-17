#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int power;
    int coeff;
    struct node *next;
};

void display(struct node *node)
{
    while(node != NULL)
    {
        if(node->next == NULL)
            printf("%d(x^%d)", node->coeff, node->power);
        else    
            printf("%d(x^%d) + ", node->coeff, node->power);
        node = node->next;
    }
    printf("\n");
}

struct node* create_node(int power, int coeff)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->power = power;
    new_node->coeff = coeff;
    new_node->next = NULL;
    return new_node;
}

void polynomial_init(int degree, struct node** head, struct node** tail)
{
    for(int i=degree; i>=0; --i)
    {
        if(*head == NULL && *tail == NULL)
        {
            printf("Enter the coefficient of the term of power %d: ",i);
            int coeff;
            scanf("%d", &coeff);
            struct node *new_node = create_node(i, coeff);
            *head = new_node;
            *tail = new_node;
        }
        else
        {
            printf("Enter the coefficient of the term of power %d: ",i);
            int coeff;
            scanf("%d", &coeff);
            struct node *new_node = create_node(i, coeff);
            (*tail)->next = new_node;
            *tail = new_node;
        }
    }
}

struct node* add_polynomial(struct node *poly1, struct node *poly2)
{
    struct node *head3 = NULL, *tail3 = NULL, *new_node;
    while(poly1 != NULL || poly2 != NULL)
    {
        if(poly1->power == poly2->power)
        {
            int power = poly1->power;
            int coefficient = poly1->coeff + poly2->coeff;
            new_node = create_node(power, coefficient);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->power > poly2->power)
        {
            new_node = create_node(poly1->power, poly1->coeff);
            poly1 = poly1->next;
        }
        else if(poly1->power < poly2->power)
        {
            new_node = create_node(poly2->power, poly2->coeff);
            poly2 = poly2->next;
        }
        else if(poly1 != NULL && poly2 == NULL)
        {
            new_node = create_node(poly1->power, poly1->coeff);
            poly1 = poly1->next;
        }
        else if(poly2 != NULL && poly1 == NULL)
        {
            new_node = create_node(poly2->power, poly2->coeff);
            poly2 = poly2->next;
        }

        if(head3 == NULL && tail3 == NULL)
        {
            head3 = new_node;
            tail3 = new_node;
        }
        else
        {
            tail3->next = new_node;
            tail3 = new_node;
        }

    }   
    return head3;
}

void free_node(struct node *polynomial)
{
    while(polynomial->next != NULL)
    {
        struct node *temp = polynomial;
	polynomial = polynomial->next;
	free(temp);
    }
}

int main()
{
    int degree1, degree2;
    struct node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
    
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    polynomial_init(degree1, &head1, &tail1);
    printf("\nThe first polynomial is:\n");
    display(head1);
    printf("\n");
    
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    polynomial_init(degree2, &head2, &tail2);
    printf("\nThe second polynomial is:\n");
    display(head2);
    printf("\n");

    struct node *head3 = add_polynomial(head1, head2);
    printf("\nThe sum of the two polynomials you entered is:\n");
    display(head3);
    free(head1);
    free(head2);
    free(head3);
    return 0;
}
