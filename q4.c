#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int facto(int n)
{
    int x,fact;
    x = 1;
    fact = 1;

    while (x<=n)
    {
        fact *=x;
        x+=1;
    }
    return fact;
}
void mainx()
{
    float e,x;
    int c,f;
    e = 1;
    c = 1;
    f = 10;
    while(c<f+1)
    {
        x = facto(c);
        e = e + (1/x);

        c += 1;
    }
    printf("%f",e);
    
}

void main()
{
    float e,x;
    int c,f,n;
    e = 1;
    c = 1;
    f = 10;
    printf("Enter the power : ");
    scanf("%d",&n);
    while(c<f+1)
    {
        x = facto(c);
        e = e + (pow(n,c)/x);
        c += 1;
    }
    printf("e^%d is %f",n,e);
    
}