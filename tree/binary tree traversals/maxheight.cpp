#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;
int max_height(treenode* root){
    if(root==NULL)return 0;
    int ans=max(max_height(root->left),max_height(root->right));
    return 1+ans;
}
int main(){
    treenode* root=new treenode(1);
    treenode* rootleft=new treenode(2);
    treenode* rootright=new treenode(3);
    treenode* rootleftleft=new treenode(4);
    treenode* rootleftright=new treenode(5);
    treenode* rootrightleft=new treenode(6);
    treenode* rootrightright=new treenode(7);
    rootleft->left=rootleftleft;
    rootleft->right=rootleftright;
    rootright->left=rootrightleft;
    rootright->right=rootrightright;
    root->left=rootleft;
    root->right=rootright;
    cout<<max_height(root);
    return 0;
}
