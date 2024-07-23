#include <stdio.h>
#define SIZE 100
int linearSearch(const int array[], int key, int size);

int main(void)
{
    int a[ SIZE ] , x , searchKey , element,c,n; 

    printf("Enter number of elements : ");
    scanf("%d",&n);
   
    c =0;

    while (c<n)
    {
        printf("Enter element %d : ",c+1);
        scanf("%d",&element);
        a[c] = element;
        c+=1;
    }

    for (x=0; x < SIZE; x++) 
    {   
        a[ x ] = 2 * x; 
    } 

    printf("Enter integer search key:\n" ); scanf("%d", &searchKey );

    element = linearSearch( a, searchKey, SIZE );
    if (element != -1) 
    {
        printf("Found value in element %d\n", element );
    }
    else 
    {
        printf("Value not found\n"); 
    } 
    return 0; 
}

int linearSearch (const int array[], int key, int size )
{
    int n; /* counter */

    for (n= 0; n < size; ++n) 
    {
        if (array[ n ]== key) 
        {
            return n+1; 
        }
    }
    return -1; /* key not found */ 
} 