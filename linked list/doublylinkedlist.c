#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
void insertathead(struct node**head,int data){
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->prev=NULL;
   newnode->next=*head;
   *head=newnode;
   printf("\nnew node is inserted successfully!!\n"); 
}
void insertattail(struct node**head,int data){
    if(*head==NULL){
        insertathead(&*head,data);
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    struct node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp; 
    printf("\nnew node is inserted successfully!!\n"); 
}
void deleteathead(struct node**head){
    struct node* temp=*head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return ;
    }
    *head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    printf("Node deleted successfully\n");
}
void deleteattail(struct node**head){
    struct node* temp=*head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return ;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    printf("Node is Deleted Successfully!\n");
}
void insert(struct node* *head){
    int t;
    printf("Enter the data of new node :");
    int data;
    scanf("%d",&data);
    printf("\nPress:-\n");
    printf("1 to insert at tail\n");
    printf("2 to insert at Head\n");
    scanf("%d",&t);
    if(t==2)insertathead(&*head,data);
    else if(t==1)insertattail(&*head,data);
}
void delete(struct node* *head){
    int t;
    printf("\nPress:-\n");
    printf("1 to Delete at tail\n");
    printf("2 to Delete at Head\n");
    scanf("%d",&t);
    if(t==2)deleteathead(&*head);
    else if(t==1)deleteattail(&*head);
}
void isempty(struct node* head){
    if(head==NULL){
        printf("List is Empty\n");
    }
    else printf("List is not empty\n");
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int t;
    struct node* head=NULL;
    while(1){
        printf("Press :-\n");
        printf("1 to insert new node\n");
        printf("2 to delete\n");
        printf("3 Isempty\n");
        printf("4 to display\n");
        scanf("%d",&t);
        switch(t){
            case 1: insert(&head);
            break;
            case 2: delete(&head);
            break;
            case 3: isempty(head);
            break;
            case 4: display(head);
            break;
            default: printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}