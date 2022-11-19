#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void creation();
void insertion();
void deletion();
void display();
void isempty();

int main()
{
    int t;
    printf("press\n 1.to enter\n 9.exit\n");
    scanf("%d", &t);
    while (t != 9)
    {
        int n;
        printf("enter\n1.print \n2.create \n3.insert \n4.delete \n5.isempty\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            display();
            break;
        case 2:
            creation();
            break;
        case 3:
            insertion();
            break;
        case 4:
            deletion();
            break;
        case 5:
            isempty();
            break;
        }
    }
    return 0;
}

void creation()
{
    struct node *p;
    p = head;
    struct node *new;
    int x;
    printf("enter the number of nodes to enter :");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int item;
        printf("enter the data:");
        scanf("%d", &item);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = item;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            p = head;
        }
        else
        {
            p->next = new;
            p = p->next;
        }
    }
    printf("\n");
}

void insertion()
{
    struct node *p;
    p = head;
    struct node *new;
    int key, item;
    printf("enter the key:");
    scanf("%d", &key);
    printf("enter the data part:");
    scanf("%d", &item);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            new->next = p->next;
            p->next = new;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    printf("\n");
}

void deletion()
{
    struct node *p;
    p = head;
    struct node *p1;
    int key;
    printf("enter the key you want to delete:");
    scanf("%d", &key);
    while (p->data!=key)
    {
        p1 = p;
        p=p->next;
        if(p==NULL)
        {
            printf("key not found\n");
        }
    }
    p1->next=p->next;
    free(p);
    printf("\n");
}

void display()
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

void isempty()
{
    struct node *p;
    p = head;
    if (head == NULL)
    {
        printf("linked list empty:");
    }
    else
    {
        printf("not empty");
    }
    printf("\n");
}