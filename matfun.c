#include <stdio.h>
#include <stdbool.h>

void setmat(int mat[3][3],int r,int c)
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

void addmat(int mat1[3][3],int mat2[3][3],int r, int c)
{
	int mat3[3][3];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
    getmat(mat3,r,c);
}

void submat(int mat1[3][3],int mat2[3][3],int r, int c)
{
	int mat3[3][3];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    getmat(mat3,r,c);
}

void mulmat(int mat1[3][3],int mat2[3][3],int r1, int c1,int c2)
{
	int mat3[3][3];
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            mat3[i][j] = 0;
            for(int k=0; k<c1; k++)
                {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
        }
    }
    getmat(mat3,r1,c2);
}

void transversemat(int mat1[3][3],int r, int c)
{
	int mat2[3][3];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
    getmat(mat2,r,c);
}

void identity(int mat[3][3],int r, int c)
{
    int f;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++){
            if(i==j&&mat[i][j] ==1)
            {
                f+=1;
            }
            else{          
                if(mat[i][j]==0){
                    f+=1;
                }
            }
        }
    }
    if(f==(c*r))
    {
        printf( "true");
    }
    else{
        printf( "false");
    } 
}
int main()
{
    int mat1[3][3],mat2[3][3];
    int r1,c1,ch,r2,c2;

    printf("Enter rows and columns of 1nd matrix:\n");
    scanf("%d %d",&r1,&c1);

    printf("Enter %d*%d matrix 1 elements :\n",r1,c1);
    setmat(mat1,r1,c1);
    

    printf("Enter rows and columns of 2nd matrix:\n");
    scanf("%d %d",&r2,&c2);

    printf("Enter %d*%d matrix 2 elements :\n",r2,c2);
    setmat(mat2,r2,c2);
    

    do{
        printf("\n");
    printf("Enter \n1.Addition\n2.Subtraction\n3.multiplication\n4.Transverse\n5.Identity\nElse for Exit\n");
    scanf("%d",&ch);
     printf("\n");
    switch(ch)
    {
    	case 1:
            printf("Displaying Matrix 1 \n");
            getmat(mat1,r1,c1);
            printf("\n");
            printf("Displaying Matrix 2 \n");
            getmat(mat2,r2,c2);
            printf("\n");

            if(r1==r2&&c2==c1)
    		{printf("Sum is - \n");
    		addmat(mat1,mat2,r1,c1);}
            else{printf("Please enter same rows and columns\n");}
			break;

    	case 2:
            printf("Displaying Matrix 1 \n");
            getmat(mat1,r1,c1);
            printf("\n");
            printf("Displaying Matrix 2 \n");
            getmat(mat2,r2,c2);
            printf("\n");
			if(r2==r1&&c2==c1)
    		{printf("Product is - \n");
    		submat(mat1,mat2,r1,c1);}
            else{printf("Please enter same rows and columns\n");}
			break;

    	case 3:
			printf("Displaying Matrix 1 \n");
            getmat(mat1,r1,c1);
            printf("\n");
            printf("Displaying Matrix 2 \n");
            getmat(mat2,r2,c2);
            printf("\n");
            if(c1==r2)
            {
                printf("Product is - \n");
			    mulmat(mat1,mat2,r1,c1,c2);
            }
            else
                printf("Row1 and Column 2 must be same \n");
			break;

    	case 4:
            printf("Displaying Matrix 1 \n");
            getmat(mat1,r1,c1);
            printf("\n");
			printf("Transverse is  - \n");
			transversemat(mat1,r1,c1);
			break;
        case 5:
            printf("Displaying Matrix 1 \n");
            getmat(mat1,r1,c1);
            printf("\n");
            printf("Is identity - ");
            identity(mat1,r1,c1);
            printf("\n");
            break;
	 	default:
    		printf("Exitiing.... \n");

    }
    }
    while(ch==1||ch==2||ch==3||ch==4||ch==5);
    
}
