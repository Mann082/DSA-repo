#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;
bool checkbalance(treenode* root){
    if(root==NULL)return true;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1)return false;
    bool lcheck=checkbalance(root->left);
    bool rcheck=checkbalance(root->right);
    if(!lcheck || !rcheck)return false;
    return true;
}
//above solution is of O(n^2) TC
 
int checkbal(treenode* root){
    if(root==NULL)return 0;
    int lh=checkbal(root->left);
    int rh=checkbal(root->right);
    if(lh==-1 || rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return max(lh,rh)+1;
}
//above solution is of O(n)TC 
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
    bool check=checkbalance(root);
    if(check)cout<<"Balanced"<<endl;
    else cout<<"Unbalanced"<<endl;
    cout<<checkbal(root)<<endl;
    return 0;
}
