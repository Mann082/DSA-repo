#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;
int diam(treenode* node, int& diamt){
    if(node==NULL)return 0;
    int lh=diam(node->left,diamt);
    int rh=diam(node->right,diamt);
    diamt=max(diamt,lh+rh);
    return 1+max(lh,rh);
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
    int dia=0;
    int ans=diam(root,dia);
    cout<<dia;
    return 0;
}