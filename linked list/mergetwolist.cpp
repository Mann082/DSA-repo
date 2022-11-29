#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
void inserthead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void inserttail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* merge(node* &head1,node* &head2){
    node* temp1=head1;
    node* temp2=head2;
    node* temp=NULL;
    node* head;
    while(temp1!=NULL && temp2!=NULL){
        node* newnode=new node();
        if(temp1->data<temp2->data){
            newnode->data=temp1->data;
            temp1=temp1->next;
            if(temp==NULL){
                temp=newnode;
                head=temp;
            }
            else{
                temp->next=newnode;
                temp=temp->next;
            }
        }
        else{
            newnode->data=temp2->data;
            temp2=temp2->next;
            if(temp==NULL){
                temp=newnode;
                head=temp;
            }
            else{
                temp->next=newnode;
                temp=temp->next;
            }
        }
    }
    if(temp1==NULL){
        temp->next=temp2;
    }
    else{
        temp->next=temp1;
    }
    return head;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    inserttail(head1,1);
    inserttail(head1,3);
    inserttail(head1,5);
    inserttail(head1,7);
    inserttail(head1,9);
    inserttail(head2,2);
    inserttail(head2,4);
    inserttail(head2,6);
    inserttail(head2,8);
    inserttail(head2,10);
        display(head1);    display(head2);
    head3=merge(head1,head2);
    display(head3);
    return 0;
}