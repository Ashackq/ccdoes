#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void main()
{
    int c,n,s;
    printf("Enter the number : ");
    scanf("%d",&n);
    c=0;
    while(c<n)
    {
        s=0;

        if (c%2 == 0)
        {
            while(s<n*2)
            {
                if(s%2==0)
                {
                   printf("*");             
                }
                else{printf(" ");}
                s+=1;
            }
            
        }

        else if(c%2!=0)
        {
            while(s<n*2)
            {
                if(s%2!=0)
                {
                   printf("*");             
                }
                else{printf(" ");}
                s+=1;
            }
        }
        printf("\n");
        c += 1;
    }
}