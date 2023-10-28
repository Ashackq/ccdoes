#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


void main()
{
    int num,i,f;
    system("cls");
    f=i=1;
    printf("Enter Number To Find Factorial:");
    scanf("%d",&num);
    while(i<=num)
    {
        if (i ==1)
        { 
            printf("%d",i);
            f*=i;
            i++;
            continue;
        }
        printf("*%d",i);
        f*=i;
        i++;
    }
    printf("\nFACTORIAL is : %d\n",f);
    getchar();
}