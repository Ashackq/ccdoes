#include<stdio.h>
void main()
{
    float costprice, profitpercent, sellingprice, profit;

    printf("cost price :"); 
    scanf("%f", &costprice);

    printf("profit percent :"); 
    scanf("%f", &profitpercent); 
    profit = profitpercent * costprice;
    sellingprice=(profit)/100+costprice;

    printf("sellingprice: %f\n", sellingprice);

}
