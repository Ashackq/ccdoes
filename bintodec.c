#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
    int bin, dec = 0;
 	printf("Enter a binary number : ");
 	scanf("%d",&bin);
 
    for(int i = 0; bin; i++, bin /= 10)
        if (bin % 10)
            dec += pow(2, i);
 
    printf("The binary number is %d", dec);
 
    return 0;
}