#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=a && arr[i]<=b)count++;
        }
        cout<<count<<endl;
    }
    return 0;
}