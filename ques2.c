#include<stdio.h>
void addition();
void multiply();
void transpose();
void determinant();
int main()
{
    printf("Press :-\n");
    printf("1 for Addition of Matrix\n");
    printf("2 for Multiplication of Matrix\n");
    printf("3 for transpose of Matrix\n");
    printf("4 for Determinant of Matrix\n");
    
    int t;
    scanf("%d",&t);
    switch(t)
    {
        case 1:
        {
            addition();
            break;
        }
        case 2:
        {
            multiply();
            break;
        }
        case 3:
        {
            transpose();
            break;
        }
        case 4:
        {
            determinant();
            break;
        }
        default:
        {
            printf("Invalid Input");
            break;
        }
    }
    return 0;
}
void addition()
{
    int mat1[3][3], mat2[3][3], i, j, mat3[3][3];
    printf("Enter elements of first matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            scanf("%d",&mat1[i][j]);
    }
    printf("Enter elements of second matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            scanf("%d",&mat2[i][j]);
    }
  
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            mat3[i][j] = mat1[i][j]+mat2[i][j];
    }
    printf("Addition result of two given matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
             printf("%d ",mat3[i][j]);
        printf("\n");
    }
}
void multiply()
{
    int mat1[3][3], mat2[3][3], i, j, mat3[3][3];
    printf("Enter elements of first matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            scanf("%d",&mat1[i][j]);
    }
    printf("Enter elements of second matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            scanf("%d",&mat2[i][j]);
    }
     for(i=0;i<3;i++)    
     {    
     for(j=0;j<3;j++)    
     {    
     mat3[i][j]=0;    
     for(int k=0;k<3;k++)    
     {    
     mat3[i][j]+=mat1[i][k]*mat2[k][j];    
     }    
     }    
     }    
    printf("The final matrix is: \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d ",mat3[i][j]);
        printf("\n");
    }
}
void transpose()
{
    int mat[3][3], i, j, matT[3][3];
    printf("Enter 9 elements for 3*3 matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            scanf("%d",&mat[i][j]);
    }
    printf("\nOriginal matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            matT[j][i] = mat[i][j];
    }
    printf("\nTranspose of given matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d",matT[i][j]);
        printf("\n");
    }
    printf("\n");
}
void determinant(){
        int mat[3][3];
    printf("Enter Matrix Elements\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int a,b,c;
    a= (mat[0][0])*((mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2]));
    b= (mat[0][1])*((mat[1][0]*mat[2][2])-(mat[2][0]*mat[1][2]));
    c= (mat[0][2])*((mat[1][0]*mat[2][1])-(mat[2][0]*mat[1][1]));
    printf("The Determinant of matrix is %d",a+b-c);
}