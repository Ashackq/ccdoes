#include<stdio.h>
#include<conio.h>
int main()
{
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(i =1; i <= n; i++)
    {
        for(j=1;j<=(2*n)-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}