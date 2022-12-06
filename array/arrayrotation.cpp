#include<iostream>
using namespace std;
class solution{
    public:
    void lrotate(int arr[],int n){
        int temp=arr[0];
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;
    }
    void rrotate(int arr[],int n){
        int temp=arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
};
int main(){
    solution solve;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Press 1 for Left rotation";
    cout<<"\nPress 2 for right rotation"<<endl;
    int t;
    cin>>t;
    cout<<"How many times you want to rotate?";
    int m;
    cin>>m;
    switch(t){
    case 1:{
        for(int i=0;i<m;i++){
            solve.lrotate(arr,n);
            cout<<"Array is rotated";
        }
        break;
    }
    case 2:{
        for(int i=0;i<m;i++){
            solve.rrotate(arr,n);
            cout<<"Array is rotated";
        }
    }
    break;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}