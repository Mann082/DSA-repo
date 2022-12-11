#include<iostream>
using namespace std;
struct node{
    int val;
    struct node* right;
    struct node* down;
};
struct node* head=NULL;
struct node* push(struct node* headref,int val){
    struct node* newnode=new node();
    newnode->val=val;
    newnode->right=NULL;
    newnode->down=headref;
    headref=newnode;
    return headref;
}
struct node* merge(struct node*a,struct node*b){
    if(a==NULL)return b;
    if(b==NULL)return a;

    node* result;
    if(a->val < b->val){
        result=a;
        result->down=merge(a->down,b);
    }
    else{
        result=b;
        result->down=merge(b->down,a);
    }
    result->right=NULL;
    return result;
}
node* flatten(struct node* root){
    //base case
    if(root==NULL || root->right==NULL){
        return root;
    }
    root->right=flatten(root->right);
    root=merge(root,root->right);
    return root;
}
void display(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->down;
    }
    cout<<endl;
}
int main(){
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    head=push(head,30);
    head=push(head,8);
    head=push(head,7);
    head=push(head,5);

    head->right=push(head->right,20);
    head->right=push(head->right,10);

    head->right->right=push(head->right->right,50);
    head->right->right=push(head->right->right,22);
    head->right->right=push(head->right->right,19);

    head->right->right->right=push(head->right->right->right,45);
    head->right->right->right=push(head->right->right->right,40);
    head->right->right->right=push(head->right->right->right,35);
    head->right->right->right=push(head->right->right->right,28);

    head=flatten(head);
    display();
    // this will print:-
    // 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50 
    return 0;
}