#include<stdio.h>

void setmat(int mat[7][7],int r, int c)
    {
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++){
                printf("Enter [%d,%d] element :\n",i,j);
                scanf("%d",&mat[i][j]);
                
            }
        }
        printf("\n");
    }

void getmat(int mat[7][7],int r, int c)
    {
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++){
                printf("%d \t",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }

void getcompact(int compact[7][3])
    {
        int nonZeroCount = compact[0][2];
        printf("Compact Matrix:\n");
        printf("Row\tColumn\tValue\n");
        printf("%d\t%d\t%d\n",compact[0][0], compact[0][1], compact[0][2]);
        for (int i = 1; i <= nonZeroCount; i++) {
            printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
        }
        printf("\n");


    }

void convertToCompactMatrix(int matrix[7][7],int compact[7][3], int rows, int columns) {
        int nonZeroCount = 0;
        int index = 1;
        compact[0][0] = rows;
        compact[0][1] = columns;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] != 0) {
                    compact[index][2] = matrix[i][j];
                    compact[index][0] = i;
                    compact[index][1] = j;
                    index++;
                    nonZeroCount++;
                }
            }
        }
        compact[0][2] = nonZeroCount;
    }

void fasttranspose(int compact[7][3], int transpose[7][3]) {
    int rowCounts[7]; 
    int startingIndex[7];
    int nonZeroCount = compact[0][2];

    for (int i = 0; i <= compact[0][1]; i++) {
        rowCounts[i] = 0;
        startingIndex[i] = 0;
    }

    for (int i = 1; i <= nonZeroCount; i++) {
        int col = compact[i][1];
        rowCounts[col]++;
    }

    startingIndex[0] = 1; 
    for (int i = 1; i <= compact[0][1]; i++) {
        startingIndex[i] = startingIndex[i - 1] + rowCounts[i - 1];
    }


    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0]; 
    transpose[0][2] = nonZeroCount; 

    for (int i = 1; i <= nonZeroCount; i++) {
        int col = compact[i][1];
        int index = startingIndex[col];

        transpose[index][0] = compact[i][1];
        transpose[index][1] = compact[i][0];
        transpose[index][2] = compact[i][2];

        startingIndex[col]++;
    }
}

void simpletranspose(int compact[7][3], int transpose[7][3]) {
    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    int nonZeroCount = transpose[0][2] = compact[0][2]; 
    for (int i = 1; i <= nonZeroCount; i++) {
        transpose[i][0] = 0;
        transpose[i][1] = 0;
        transpose[i][2] = 0;
    }

    int index = 1;
    for (int col = 0; col < compact[0][1]; col++) {
        for (int i = 1; i <= nonZeroCount; i++) {
            if (compact[i][1] == col) {
                transpose[index][0] = compact[i][1];
                transpose[index][1] = compact[i][0];
                transpose[index][2] = compact[i][2];
                index++;
            } 
        }
    }
}


int main() {
    int mat1[7][7];
    int compact[7][3];
    int transpose[7][3];
    int r, c;
    printf("Enter number of rows:\n");
    scanf("%d", &r);
    printf("Enter number of columns:\n");
    scanf("%d", &c);
    printf("Enter %d*%d matrix elements:\n", r, c);
    setmat(mat1, r, c);
    getmat(mat1, r, c);
    convertToCompactMatrix(mat1, compact, r, c);
    getcompact(compact);

    int choice;
    printf("Choose transpose type:\n");
    printf("1. Fast Transpose\n");
    printf("2. Simple Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fasttranspose(compact, transpose);
            printf("\nTranspose Sparse Matrix (Fast Transpose):\n");
            getcompact(transpose);
            break;

        case 2:
            simpletranspose(compact, transpose);
            printf("\nTranspose Sparse Matrix (Simple Transpose):\n");
            getcompact(transpose);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}