#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* link;
    node(int val){
        data=val;
        link=NULL;
    }
};

void create(node* &head,int n){
    cout<<"Enter the Data of Nodes :"<<endl;
    int temp;
    cin>>temp;
    node* pnode= new node(temp);
    head=pnode;
    for(int i=0;i<n-1;i++){
        cin>>temp;
        node* newnode= new node(temp);
        pnode->link=newnode;
        pnode=newnode;
    }
    cout<<endl;
    cout<<"List Created"<<endl;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->link;
    }
    cout<<endl;
}

void makecycle(node* &head,int pos){
    node* temp;
    node* cyclestart;
    temp=head;
    int count=1;
    while(temp->link!=NULL){
        if(count==pos){
            cyclestart=temp;
        }
        temp=temp->link;
        count++;
    }
    temp->link=cyclestart;
}

bool checkcycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->link!=NULL){
        fast=fast->link->link;
        slow=slow->link;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void clearcycle(node* &head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->link!=NULL){
        fast=fast->link->link;
        slow=slow->link;
        if(fast==slow){
            break;
        }
    }
    fast=head;
    while(fast->link!=slow->link){
        fast=fast->link;
        slow=slow->link;
    }
    slow->link=NULL;
}
int main(){
    int n;
    node* head=NULL;
    cout<<"Enter the Number of Node you want to put : ";
    cin>>n;
    create(head,n);
    display(head);
    makecycle(head,6);
    // display(head);
    // the algorithm used here is called floyd's algorithm or hare and tortoise algortihm
    cout<<checkcycle(head)<<endl;
    clearcycle(head);
    display(head);
    return 0;
}