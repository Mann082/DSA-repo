#include <stdio.h>
#include <math.h>
int factorial(int n);
int fib(int n);
int gcd(int a, int b);
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
int main()
{
    printf("Press :-\n");
    printf("1 for factorial\n");
    printf("2 for fibonacci\n");
    printf("3 for gcd calculation\n");
    printf("4 for tower of hanoi\n");
    int t;
    scanf("%d",&t);
    switch(t)
    {
        case 1:
        {
            printf("Enter any Number :");
            int n;
            scanf("%d",&n);
            printf("Factrial Of given number is %d",factorial(n));
            break;
        }
        case 2:
        {
            printf("Which term of fibnacci series you want? :");
            int n;
            scanf("%d",&n);
            printf("%d", fib(n));
            break;
        }
        case 3:
        {
            printf("Enter Two Numbers :");
            int a,b;
            scanf("%d%d",&a,&b);
            printf("GCD of %d and %d is %d",a,b,gcd(a,b));
            break;
        }
        case 4:
        {
            int N;
            printf("How many disc in the puzzle? :");
            scanf("%d",&N);
            // A, B and C are names of rods
            towerOfHanoi(N, 'A', 'C', 'B');
            break;
        }
        default:
        printf("Invalid Input");
    }
    return 0;
}
int factorial(int n)
{
    if(n==1)return 1;
    else return n*factorial(n-1);
}
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n",n,from_rod,to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
