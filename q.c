#include <stdio.h>

void main()
{
    int i,j,k;
    for (i=1;i<=5;i++)
    {
        for(j=1;j<=3;j++)
        {
            for(k=1;k<=4;k++)
            {printf("*");}
            printf("\n");
        }
        printf("\n");
    }
}