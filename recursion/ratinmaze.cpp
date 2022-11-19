#include<bits/stdc++.h>
using namespace std;
bool issafe(int **arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinmaze(int** arr,int x,int y, int n,int ** solArr){
    if((x==(n-1)) && (y==(n-1))){
        solArr[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(ratinmaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinmaze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y]=0;     //backtracking
        return false;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ** solarr=new int*[n];
    for(int i=0;i<n;i++){
        solarr[i]=new int[n];
        for(int j=0;j<n;j++){
            solarr[i][j]=0;
        }
    }
    cout<<endl<<"-----------------------------"<<endl;
    if(ratinmaze(arr,0,0,n,solarr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution"<<endl;
    }
    return 0;
}