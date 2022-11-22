#include<iostream>
using namespace std;
#define ndoe node
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(node* &head,int val){
    node* n=new node(val);
    if(head!=NULL){
        head->prev=n;
        n->next=head;
    }
    head=n;
}
void insertattail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void deleteathead(node* &head){
    node* temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    delete(temp);
}
void deletenode(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        deleteathead(head);
        return;
    }
    int count=1;
    while(count!=pos){
        count++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)temp->next->prev=temp->prev;
    delete(temp);
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int temp;
    node* head=NULL;
    cout<<"How many nodes do you want in list?  :";
    cin>>temp;                      
    for(int i=1;i<=temp;i++){
        int n;
        cout<<"Enter the data of "<<i<<"th node :";
        cin>>n;
        insertattail(head,n);               //creating the list
    }
    cout<<"Given List is :";
    display(head);
    int k;
    cout<<"Which node you want to delete? :";
    cin>>k;
    deletenode(head,k);   //deleting 4th node
    display(head);
    return 0;
}