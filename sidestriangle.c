#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void main()
{
    float n1,n2,n3;

    printf("Enter the number 1: ",n1);
    scanf("%d",&n1);
    printf("Enter the number 2: ",n2);
    scanf("%d",&n2);
    printf("Enter the number 3: ",n3);
    scanf("%d",&n3);
    if ((((n1+n2)<=n3) || ((n1+n3)<=n2)) || ((n3+n2)<=n1))
    {
        printf("A triangle cannot be formed.\n" );
    }
    else{printf("A triangle can be formed.\n" );}

    if ((((pow(n1,2)+pow(n2,2)) == pow(n3,2)) || ((pow(n1,2) + pow(n3,2)) == pow(n2,2))) || ((pow(n3,2)+pow(n2,2)) == pow(n1,2)))
    {
        printf("Bro the triangle if right.\n");
    }
}    