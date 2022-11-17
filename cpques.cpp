#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the given number :";
    int num;
    cin>>num;
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    cout<<"Enter array elements :"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int i=0,j=n-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    int temp;
    while(i<j)
    {
        temp=arr[i]+arr[j];
        if(temp>num)j--;
        if(temp<num)i++;
        if(temp==num)
        {
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            i++;
            j--;
        }
    }
}