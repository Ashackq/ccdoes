 #include <stdio.h>  
 #include <stdlib.h>

 void main()  
 {
    float a1,a2,a3,a4,a5;
    float avg;

    printf("Enter Marks for Subject 1 : ");
    scanf("%f",&a1);

    printf("Enter Marks for Subject 2 : ");
    scanf("%f",&a2);

    printf("Enter Marks for Subject 3 : ");
    scanf("%f",&a3);

    printf("Enter Marks for Subject 4 : ");
    scanf("%f",&a4);

    printf("Enter Marks for Subject 5 : ");
    scanf("%f",&a5);

    avg = (a1+a2+a3+a4+a5)/5;
    
    if ((a1 > 40) && (a2 > 40) && (a3 > 40) && (a4 > 40) && (a5 > 40))
    {
        printf("Pass!!!\n");
        
    }
    else
    {
        printf("Fail\n");
        return 0;
    }
    if (avg > 75){printf("Distinction!!!");}
    else if (avg >= 60 && avg < 75){printf("First Division!!!");}
    else if (avg >= 50 && avg < 60){printf("Second Division!!!");}
    else {printf("Third Division!!!");}
   
    return 0;
 }