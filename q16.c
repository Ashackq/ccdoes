#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str1[20],str2[20];
    int ch,i,j;
    do
    {
        printf("\tMENU");
        printf("\n------------------------------\n");
        printf("1:Find Length of String");
        printf("\n2:Find Reverse of String");
        printf("\n3:Compare Strings");
        printf("\n4:Pallindrome");
        printf("\n5:Substring");
        printf("\n6:Exit");
        printf("\n------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter String: ");
                scanf("%s",str1);
                i=strlen(str1);
                printf("Length of String : %d\n\n",i);
            break;

            case 2:
                printf("Enter String: ");
                scanf("%s",str1);
                //strrev(str1);
                printf("Reverse string : %s\n\n",str1);
            break;

            case 3:
                printf("Enter First String: ");
                scanf("%s",str1);
                printf("Enter Second String: ");
                scanf("%s",str2);
                j=strcmp(str1,str2);
                if(j==0)
                {
                    printf("Strings are Same\n\n");
                }
                else
                {
                    printf("Strings are Not Same\n\n");
                }
            break;

            case 4:
                int temp,reverse,n,digit,d;
                printf("Enter the number : ");
                scanf("%d",&n);
                
                temp = n;

                while(n>0)
                {
                    d = n%10;
                    reverse = reverse*10 + d;
                    n = n/10;
                }

                if(temp == reverse)
                { 
                    printf("The number is pallindrome");
                }
                else
                {
                    printf("The number is not pallindrome" );
                }

            break;

            case 5: 
                char str[80], search[10];
                int count1 = 0, count2 = 0, i, j, flag;
                printf("Enter a string:");
                scanf("%s",str);
                printf("Enter search substring:");
                scanf("%s",search);
                while (str[count1] != '\0')
                    count1++;
                while (search[count2] != '\0')
                    count2++;
                for (i = 0; i <= count1 - count2; i++)
                {
                    for (j = i; j < i + count2; j++)
                    {
                        flag = 1;
                        if (str[j] != search[j - i])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1)
                        break;
                }
                if (flag == 1)
                {
                    printf("SEARCH SUCCESSFUL!");
                }
                else
                {
                    printf("SEARCH UNSUCCESSFUL!");
                }

            break;

            case 6:
                exit(0);
            break;
            
            default:
                printf("Invalid Input. Please Enter valid Input.\n\n ");
        }
    }while(ch!=6);
    return 0;
}