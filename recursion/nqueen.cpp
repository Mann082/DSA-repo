#include<iostream>
using namespace std;

bool safecheck(int x, int y, int n, int** ans){
    for(int i=0;i<x;i++){
        if(ans[i][y]==1)return false;
    }
    int row=x,col=y;
    while(row>=0 && col>=0){
        if(ans[row][col]==1)return false;
        row--;
        col--;
    }
    row=x,col=y;
    while(row>=0 && col<n){
        if(ans[row][col]==1)return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** ans,int x,int n){
    if(x>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(safecheck(x,i,n,ans)){
            ans[x][i]=1;
            if(nQueen(ans,x+1,n))return true;
            ans[x][i]=0;                            //backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int** ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i] =new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=0;
        }
    }    
    if(nQueen(ans,0,n)){
        cout<<"------------------"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"No solution";
    return 0;
}