#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void main()
{
    int n,nn,d,c,nnn;
    c = 1;
    n =1234;
    nn=0;
    nnn = 0;
    d=0;
    while(n>0)
    {
        d = n%10;
        if (c == 1)
        {
            nn = nn + d*100;
        }
        if (c == 10)
        {
            nn = nn + d*1000;
        }
        if (c == 100)
        {
            nn = nn + d*1;
        }
        if (c == 1000)
        {
            nn = nn + d*10;
        }
        n /= 10;
        c *= 10;
    }
    printf("%d\n",nn);
    
    d=0;
    c=1;
    while (nn>0)
    {
        d = ((nn%10)+3);
        nnn = nnn + d*c;
        c *= 10;
        nn/=10;
    } 



    printf("%d\n",nnn );
}