#include <stdio.h>
#include <stdlib.h>
 

int main()
{
    struct Employee{
    char name[30], degn[30],gender[1];
    int dd, mm, yy;
    double salary;
    };
 
    int n;
    printf("Enter number of employees :");
    scanf("%d",&n);
    struct Employee employees[n];

    printf("Enter %d Employee Details \n \n",n);
    for(int i=0; i<n; i++){
        printf("Employee %d:- \n",i+1);

        //Name
        printf("Name: ");
        scanf("%s",employees[i].name);

        //ID
        printf("Enter date (dd/mm/yy) format: ");
        scanf("%d/%d/%d", &employees[i].dd, &employees[i].mm, &employees[i].yy);

        //Salary
        printf("Salary: ");
        scanf("%lf",&employees[i].salary);


        char ch = getchar();
 
        printf("\n");
    }
 

    printf("-------------- All Employees Details ---------------\n");
    //a
    printf("Total number of employees : %d",n);
    
    for(int i=0; i<n; i++)
    {
        printf("Name \t: ");
        printf("%s \n",employees[i].name);
 
        printf("Id \t: ");
        printf("%d \n",employees[i].id);
 
        printf("Salary \t: ");
        printf("%.2lf \n",employees[i].salary);
 
        printf("\n");
    }
 
    return 0;
}