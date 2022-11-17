#include<bits/stdc++.h>
#include <climits>
using namespace std;
int main()
{
    int arr[4]={10,20,30,40};
    int sum1=100,sum2=0;
    int temp1=0,temp2=INT_MAX;
    for(int i=0;i<4;i++)
    {
        sum2+=arr[i];
        sum1-=arr[i];
        temp1=max(sum1,sum2);
        temp2=min(temp1,temp2);
    }
    cout<<temp2<<endl;
    return 0;
}