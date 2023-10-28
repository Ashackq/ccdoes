#include<stdio.h>  
 
  
int main()  
{  
    int N;
    printf("Enter numeber of elements ");
    scanf("%d",&N);
    
    int a[N], even[N], odd[N], i, k1 = 0, k2 = 0;  
  
    printf("Enter %d integer numbers\n", N);  
    for(i = 0; i < N; i++)  
    {  
        scanf("%d", &a[i]);  
  
        if(a[i] % 2 == 0)  
            even[k1++] = a[i];  
        else  
            odd[k2++] = a[i];  
    }  
  
    printf("\n\nArray elements of even[%d] are ...\n", k1);  
    for(i = 0; i < k1; i++)  
        printf("%d\t", even[i]);  
  
    printf("\n\nArray elements of odd[%d] are ...\n", k2);  
    for(i = 0; i < k2; i++)  
        printf("%d\t", odd[i]);  
  
    printf("\n");  
  
    return 0;  
}  
 
