#include<bits/stdc++.h>
using namespace std;
int counter(int idx,int aux, vector<int> vec,int k){
    if(idx>=vec.size()){
        if(aux==k)return 1;
        return 0;
    }
    aux+=vec[idx];
    int l=counter(idx+1,aux,vec,k);
    aux-=vec[idx];
    int r=counter(idx+1,aux,vec,k);
    return l+r;
}
int main(){
    int n;
    cout<<"Enter Number of elements in list :";
    cin>>n;
    vector<int> vec;
    cout<<"Enter the data : ";
    while(n--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    cout<<"Enter Target Sum : ";
    int target;
    cin>>target;
    cout<<"The Number of Subsequences are : "<<counter(0,0,vec,target);
    return 0;
}