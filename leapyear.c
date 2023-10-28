 #include <stdio.h>  
 #include <stdlib.h>

 void main()  
 {
    int n;
    printf("Enter a year: ");
    scanf("%d",&n);
    if (n>=400)
    {
        if (n%400 == 0){printf("Year is leap.");}
        else if (n%100 == 0){printf("Year is not leap.");}
        else if (n%4 == 0){printf("Year is leap.");}
    }
    else {printf("Year is not leap.");}
 }
 