#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    string data;
    node* left;
    node* right;
    node(string n){
        data=n;
        left=NULL;
        right=NULL;
    }
};
void preorder(node* &n){
    if(n==NULL){
        return;
    }
    cout<<n->data;
    preorder(n->left);
    preorder(n->right);
}
void postorder(node*&n){
    if(n==NULL)return;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data;
}
void inorder(node* &n){
    if(n==NULL)return;
    inorder(n->left);
    cout<<n->data;
    inorder(n->right);
}
int main(){
    node* n=new node("X");
    node* temp1=new node("L");
    n->left=temp1;
    node* temp2=new node("R");
    n->right=temp2;
    preorder(n);
    postorder(n);
    inorder(n);
    return 0;
}