#include<stdio.h>

int linearsearch(int arr[],int size,int search){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==search){
        return i;
        }
    }
    return -1;
    
}

int main()
{
    int size;  scanf("%d",&size);
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
    
    int search; printf("\nenter the element you want to search :"); 
    scanf("%d",&search);
    if(linearsearch(arr,size,search)!=-1)
    printf("present at index = %d",linearsearch(arr,size,search));
    else
    printf("Element not present in array");
    
    return 0;
}