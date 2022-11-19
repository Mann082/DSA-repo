#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
int main()
{
    int n;
    struct node* head=NULL;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    struct node* new;
    struct node* p;
    head=p;
    for(int i=1;i<=n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        int temp;
        printf("Enter the data of %dth node:",&temp);
        new->data=temp;
        new->link=NULL;
        p->link=new;
        p=p->link;
    }
    struct node* m=(struct node*)malloc(sizeof(struct node));
    
}