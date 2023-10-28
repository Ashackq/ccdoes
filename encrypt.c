#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void main()
{
    int n,nn,d,c,nnn;
    c = 1;
    n =1234;
    nn=0;
    while (n>0)
    {
        d = ((n%10)+7)%10;
        nn = nn + d*c;
        c *= 10;
        n/=10;
    }
    d=0;
    c=1;
    nnn = 0;
    printf("%d\n",nn);
    while(nn>0)
    {
        d = nn%10;
        printf("d = %d\n",d);
        if (c == 1)
        {
            nnn = nnn + d*100;
        }
        if (c == 10)
        {
            nnn = nnn + d*1000;
        }
        if (c == 100)
        {
            nnn = nnn + d*1;
        }
        if (c == 1000)
        {
            nnn = nnn + d*10;
        }
        nn /= 10;
        c *= 10;
    }
    printf("%d\n",nnn );
}