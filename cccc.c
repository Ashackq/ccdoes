#include <stdio.h>
void main()
{
    char n;
    int a,b;
    printf("enter operator : ");
    scanf("%c", &n);
    printf("enter a : ");
    scanf("%d", &a);
    printf("enter b : ");
    scanf("%d", &b);

    switch (n)
    {
        case '+':
        printf("%d",a+b);
        break;
        
        case '-':
        printf("%d",a-b);
        break;
        
        case '*':
        printf("%d",a*b);
        break;
        
        case '/':
        printf("%d",a/b);
        break;
        
        default:
        printf("invalid choice");
    }
}