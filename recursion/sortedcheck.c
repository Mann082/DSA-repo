#include<stdio.h>
int checksort(int arr[],int n){
    if(n==1){
        return 1;
    }
    else{
        if(arr[n-1]<arr[n-2])return 0;
        else return checksort(arr,n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(checksort(arr,n)==1)printf("Sorted");
    else printf("NOt sorted");
    return 0;
}