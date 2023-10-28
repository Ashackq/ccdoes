#include<stdio.h>
#include<conio.h>
int main()
{
    int  n, i, j,k,m;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(i = n; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(j=i)
            {
                printf("*");
            }
            else
            {
                printf("* ");
            }
        }
        
    
       
      
        for (j = i; j <= 2*n-1; j++)   
        {  
            
            printf(" ");   
        }  
        for (k = 1; k <= i; k++)  
        {  
            if(k=i)
            {
                printf("*");
            }
            else
            {
                printf("* ");
            }
        }  
        printf ("\n");   
    }  
    return 0;
}
 
     
    
