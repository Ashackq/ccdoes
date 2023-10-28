#include <stdio.h> 


int main(void)
{

    int a[10] = {0};
    int pass,i,hold,element,n,c;
    c =0;
// input array
    printf("Enter number of elements : ");
    scanf("%d",&n);
   

    while (c<n)
    {
        printf("Enter element %d : ",c+1);
        scanf("%d",&element);
        a[c] = element;
        c+=1;
    }

//original
    printf("Data items in original order\n");
    for (i = 0; i < n; i++ ) 
    {
        printf("%4d", a[ i ] );
    }
/* bubble sort */
    for ( pass = 1; pass < n; pass++) 
    {
        for (i=0; i < n - 1; i++) 
        {
            if (a[i]> a[i+1]) 
            { 
                hold = a[ i ];
                a[i]=a[i + 1]; 
                a[i+1] = hold;
            }
        }
    }

    printf("\nData items in ascending order\n");

    for (i = 0; i < n; i++ ) 
    {
         printf("%4d", a[ i ] );
    } 
    printf("\n" );
    return 0; 
} 
