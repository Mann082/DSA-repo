#include<stdio.h>

int binarysearch(int arr[],int size,int search){
    int s=0;
    int e=size;
    
    while(s<=e){
        int mid=(s+e)/2;

        if (arr[mid]==search){
            return mid;
        }

        else if(arr[mid]>search){
          e=mid-1;
        }

        else{
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int size; 
    scanf("%d",&size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
      printf("array is ");
       for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    int search; 
    printf("\nenter the element you want to search :"); 
    scanf("%d",&search);
    if(binarysearch(arr,size,search)!=-1)
    printf("present at index = %d",binarysearch(arr,size,search));
    else
    printf("Element not present in array");
    return 0;
}