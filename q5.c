#include<stdio.h> 

int main()
{

    int i;

    struct student
    {
    int rn; 
    char name[20];
    int m1,m2, m3;
    int total; 
    float perc;
    };

    struct student s[3]; 
    for(i=0;i<3;i++)

    {

        printf("Enter the roll number:");
        scanf("%d",&s[i].rn); 
        printf("Enter the name:");
        scanf("%s",s[i].name);
        printf("Enter the marks:"); 
        scanf("%d %d %d",&s[i].m1,&s[i].m2,&s[i].m3);
    }
    printf("Roll no\t Name\t m1\t m2 \t m3\t Total \t Percentage");

    for (i=0;i<3;i++)
    {
        s[i].total=(s[i].m1+s[i].m2+s[i].m3);
        s[i].perc = s[i].total/3;
        printf("\n%d\t %s\t %d\t%d \t%d\t%d\t%f",s[i].rn,s[i].name,s[i].m1,s[i].m2,s[i].m3,s[i].total,s[i].perc);
    }
}