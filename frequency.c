#include <stdio.h> 


int main(void)
{
    int loop,max;
    int answer,rating,n,element,c,len;
    c = 0; 
    int frequency[10] = {0};
    int responses[10]  = {0};

// User input array
    printf("Enter number of elements : ");
    scanf("%d",&n);
   

    while (c<n)
    {
        printf("Enter element %d : ",c+1);
        scanf("%d",&element);
        responses[c] = element;
        c+=1;
    
    }

//Count value of element      
    for (answer = 0; answer< n; answer++) 
    {
         ++frequency [ responses [ answer ]];
    } 
    printf("%s%17s\n", "Rating", "Frequency" );

// MAX
    for (int i = 0; i < n; i++) 
    {     
        
       if(responses[i] > max)    
           max = responses[i];    
    }      
       
//Corresponding element
    for (rating = 1; rating <= max; rating++ ) 
    { 
        if (frequency [ rating ] > 0)
            printf("%6d%17d\n", rating, frequency [ rating ]); 
    }




 