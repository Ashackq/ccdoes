#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void main()
{
    int n,c,d;
    printf("Enter the number : ");
    scanf("%d",&n);
    while(n>0)
    {
        d = n%10;
        printf("d =  %d\n",d );
        if (d == 7)
        {
            c+=1;
        }
        n = n/10;
    }
    printf("Number of 7s are : %d\n",c );
}