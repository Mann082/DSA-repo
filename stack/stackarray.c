#include<stdio.h>
int top=-1;

void push(int stk[])
{
    if(top==19){
        printf("Stack oveflow");
        return;
    }
    top++;
    int temp;
    printf("Enter the value to push : ");
    scanf("%d",&temp);
    stk[top]=temp;
    printf("value is pushed\n");
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow ");
        return;
    }
    top=top-1;
}
void isempty()
{
    if(top==-1) printf("stack is empty");
    else printf("Stack is not empty\n");
}
void isfull()
{
    if(top==19) printf("stack is full");
    else printf("Stack is not full");
}
void display(int stack[])
{
    for(int i=top;i>=0; i--)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
  int stack[20];
  while(1){
    printf("press :-\n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for isempty\n");
    printf("4 for isfull\n");
    printf("5 for display\n");
    int t;
    scanf("%d",&t);
    switch(t)
    {
        case 1:
        push(stack);
        break;

        case 2:
        pop();
        break;

        case 3:
        isempty();
        break;
        
        case 4:
        isfull();
        break;

        case 5:
        display(stack);
        break;

        default :
        printf("input not found ");
    }
  }
  return 0;
}
