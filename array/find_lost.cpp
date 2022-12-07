#include<iostream>
using namespace std;
int main(){
    cout<<"Enter first array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"Enter second array"<<endl;
    int m;
    cin>>m;
    int brr[m];
    for(int i=0;i<m;i++)cin>>brr[i];
    //now checking
    int i=0,j=0;
    while(i<n && j<m){
        if(arr[i]==brr[j]){
            i++,j++;
            continue;
        }
        else if(arr[i]!=brr[j])break;
    }
    if(i==n)cout<<brr[n]<<endl;
    else if(j==m)cout<<arr[m]<<endl;
    else{
        if(arr[i]==brr[j+1])cout<<brr[j]<<endl;
        else if(arr[i+1]==brr[j])cout<<arr[i]<<endl;
    }
    return 0;
}