 #include <stdio.h>  
 int main()  
{  

    int dec,ones,tens,hun,tho;
    char total;

    printf("Enter a number : ");
    scanf("%d",&dec);

    char i[][10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    char l[][10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char c[][10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};       
    char m[][10] = {"","M","MM","MMM","MV'","V'","V'M","V'MM","V'MMM","MX'"};
    
    ones = dec%10;
    tens = dec/10;
    hun =  dec/100;    
    tho =  dec/1000;
    
    printf("The roman is : %s%s%s%s",m[tho], c[hun], l[tens] , i[ones]);

}