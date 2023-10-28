#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
    int c;
    c=1;
    while(c<101)
    {
        if (c%10 == 0)
        {
            printf("*\n");
        }
        else
        {
            printf("*");
        }
        c = c +  1;
    }
}