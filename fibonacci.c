#include <stdio.h>

void main()
{
    int nu;
    int result;
    printf("Enter a number : ");
    scanf("%d",&nu);
    result = fibonacci(nu);
    printf("Fibonacci of %d is %d",nu,result );
}

int fibonacci(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }

}
