#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;
int maxpathsum(treenode* node,int &maxm){
    if(node==NULL)return 0;
    int ls=maxpathsum(node->left,maxm);
    int rs=maxpathsum(node->right,maxm);
    maxm=max(maxm,ls+rs+node->data);
    return node->data + max(ls,rs);
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
    int hei=0,maxm=0;
    hei=maxpathsum(root,maxm);
    cout<<maxm<<endl;
    return 0;
}