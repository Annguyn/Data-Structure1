#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int heso;
    int mu;
    struct Node *next;
} Node;

typedef struct Poly
{
    Node *head;
    int degree;
} Poly;

Poly *createPoly()
{
    Poly *p = (Poly *)malloc(sizeof(Poly));
    p->head = NULL;
    p->degree = -1;
    return p;
}

void insertTerm(Poly *p, int heso, int mu)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->heso = heso;
    newNode->mu = mu;
    newNode->next = NULL;
    if (p->head == NULL)
    {
        p->head = newNode;
        p->degree = mu;
    }
    else
    {
        Node *curr = p->head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        if (mu > p->degree)
        {
            p->degree = mu;
        }
    }
}

void addPoly(Poly *p1, Poly *p2)
{
    Poly *result = createPoly();
    Node *curr1 = p1->head;
    Node *curr2 = p2->head;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->mu == curr2->mu)
        {
            insertTerm(result, curr1->heso + curr2->heso, curr1->mu);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->mu > curr2->mu)
        {
            insertTerm(result, curr1->heso, curr1->mu);
            curr1 = curr1->next;
        }
        else
        {
            insertTerm(result, curr2->heso, curr2->mu);
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL)
    {
        insertTerm(result, curr1->heso, curr1->mu);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        insertTerm(result, curr2->heso, curr2->mu);
        curr2 = curr2->next;
    }
    p1->head = result->head;
    p1->degree = result->degree;
}

void multiplyPoly(Poly *p1, Poly *p2)
{
    Poly *result = createPoly();
    Node *curr1 = p1->head;
    while (curr1 != NULL)
    {
        Node *curr2 = p2->head;
        while (curr2 != NULL)
        {
            int heso = curr1->heso * curr2->heso;
            int mu = curr1->mu + curr2->mu;
            insertTerm(result, heso, mu);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    p1->head = result->head;
    p1->degree = result->degree;
}

void printPoly(Poly *p)
{
    Node *curr = p->head;
    while (curr != NULL)
    {
        printf("%dx^%d", curr->heso, curr->mu);
        if (curr->next != NULL)
        {
            printf(" + ");
        }
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Poly *p1 = createPoly();
    insertTerm(p1, 3, 2);
    insertTerm(p1, 4, 1);
    insertTerm(p1, 5, 0);
    printf("p1(x) = ");
    printPoly(p1);

    Poly *p2 = createPoly();
    insertTerm(p2, 2, 3);
    insertTerm(p2, 1, 1);
    printf("p2(x) = ");
    printPoly(p2);

    printf("p1(x) + p2(x) = ");
    addPoly(p1, p2);
    printPoly(p1);

    printf("p1(x) * p2(x) = ");
    multiplyPoly(p1, p2);
    printPoly(p1);

    return 0;
}
