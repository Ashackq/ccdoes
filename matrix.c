#include<stdio.h>

void setmat(int mat[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++){
            printf("Enter [%d,%d] element :\n",i,j);
            scanf("%d",&mat[i][j]);
            
        }
    }
}

void getmat(int mat[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++){
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
}

void addmat(int mat1[3][3],int mat2[3][3],int mat3[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}

void submat(int mat1[3][3],int mat2[3][3],int mat3[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void submat(int mat1[3][3],int mat2[3][3],int mat3[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void mulmat(int mat1[3][3],int mat2[3][3],int mat3[3][3],int r1, int c1,int r2)
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = 0;
            for(int k=0; k<c; k++)
                {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
        }
    }
}

void transverse(int mat1[3][3],int mat2[3][3],int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat2[i][j] = mat1[i][j]
        }
    }
}

int main()
{
    int mat1[3][3], mat2[3][3], i, j, mat3[3][3];
    int r =3,c=3;
    printf("Enter 3*3 matrix 1 elements :\n");
    setmat(mat1,r,c);
    
    printf("Enter 3*3 matrix 2 elements :\n");
    setmat(mat2,r,c);

    printf("\nAdding the two matrix.....");
    addmat(mat1,mat2,mat3,r,c);

    printf("\nBoth matrix added successfully!");
    printf("\nHere is the new matrix:\n");
    
    getmat(mat3,r,c);

    return 0;

}