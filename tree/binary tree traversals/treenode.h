#pragma once
#include<iostream>
using namespace std;
class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int height(treenode* root){
    if(root==NULL)return 0;
    int ans=max(height(root->left),height(root->right));
    return 1+ans;
}