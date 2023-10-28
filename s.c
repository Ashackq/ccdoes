#include <stdio.h>
 
void main()
{
    int a,b,c;
    printf("Enter numbers : ");
    scanf("%d %d",&a,&b);
    printf("Original Values a = %d, b = %d\n",a,b);
    c=a;
    a=b;
    b=c;
    printf("Swapped Values a = %d, b = %d",a,b);
}
