#include<stdio.h>
#include<conio.h>
int main()
{
    int  n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i = 1; i < n; i+=2)
    {
        for(int j = 1; j <= i; j++)
            printf("%d ",j);
            printf("\n");
    }
    for(int i = n; i >= 0; i-=2)
    {
        for(int j = 1; j <= i; j++)
            printf("%d ",j);
            printf("\n");
    }
    return 0;
}