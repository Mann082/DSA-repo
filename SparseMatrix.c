#include<stdio.h>
struct sparse
{
    int row;
    int column;
    int value;
};

int main()
{
    int t;
    printf("Press:-\n");
    printf("1 for Matrix to Sparse\n");
    printf("2 for Sparse to Matrix\n");
    scanf("%d",&t);
    switch(t)
    {
        case 1:
        {
            int n,m,nonzero=0;
            printf("Enter the Size of matrix :");
            scanf("%d%d",&n,&m);
            int arr[n][m];
            printf("Enter Matrix elements:\n");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    scanf("%d",&arr[i][j]);
                    if(arr[i][j]!=0)nonzero++;
                }
            }
            //creation of sparse matrix
            struct sparse mat[nonzero];
            int k=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(arr[i][j]!=0)
                    {
                        mat[k].row=i;
                        mat[k].column=j;
                        mat[k].value=arr[i][j];
                        k++;
                    }
                }
            }
            //printing of sparse matrix
            for(int i=0;i<nonzero;i++)
            {
                printf("row=%d  column=%d  value=%d\n", mat[i].row, mat[i].column, mat[i].value);
            }
            break;
        }
        case 2:
        {
            int n;
            printf("Enter the size of Sparse Matrix\n");
            scanf("%d",&n);
            int a,b;
            printf("Enter the size of Matrix:");
            scanf("%d%d",&a,&b);
            struct sparse mat[n];
            int arr[a][b];
            for(int i=0;i<a;i++)for(int j=0;j<b;j++)arr[i][j]=0;
            printf("Enter Elements :-\n");
            for(int i=0;i<n;i++)
            {
                printf("For %dth element Enter Value,Row,Column : ",i+1);
                scanf("%d",&mat[i].value);
                scanf("%d",&mat[i].row);
                scanf("%d",&mat[i].column);
                printf("\n");
                arr[mat[i].row][mat[i].column]=mat[i].value;
            }
            printf("The Original Matrix was :\n");
            for(int i=0;i<a;i++)
            {
                for(int j=0;j<b;j++)
                {
                    printf("%d ",arr[i][j]);
                }
                printf("\n");
            }
            break;
        }
        default:
        printf("Invalid Input");
    }
    return 0;
    
}