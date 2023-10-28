#include <stdio.h>
#include <math.h>

int main() 
{

  char operator;
  printf("Enter an operator (a for square root \n b for square \n c for cube \n d for prime \n e for factorial \n f prime factors): ");
  scanf("%c", &operator);


  switch (operator) 
  {
    case 'a':
        float squareRoot, n;
        printf("Number - ");
        scanf("%f",&n);
        squareRoot = sqrt(n);
        break;

    case 'b':
        float n;
        printf("Number - ");
        scanf("%f",&n);
        printf("%f",n*n);
        break;

    case 'c':
        float n;
        printf("Number - ");
        scanf("%f",&n);
        printf("%f",n*n*n);
        break;

    case 'd':
        int n;
        printf("Number - ");
        scanf("%f",&n);
        prime(n);
        break;

    case 'e':
        int n;
        printf("Number - ");
        scanf("%f",&n);
        facto(n);
        break;

    case 'f':
        int n;
        printf("Number - ");
        scanf("%f",&n);
        primeFactors(n);
        break;

    default:
      printf("Error! operator is not correct");
  }

}

void prime(int n)
{    
    int i,m=0,flag=0;       
    m=n/2;    
    for(i=2;i<=m;i++)    
    {    
        if(n%i==0)    
        {    
        printf("Number is not prime");    
        flag=1;    
        break;    
        }    
    }    
    if(flag==0)    
    printf("Number is prime");      
}  
 
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

void primeFactors(int n)
{
   
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
   
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
    
    if (n > 2)
        printf ("%d ", n);
}