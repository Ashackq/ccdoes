#include <stdio.h>

void main()
{
	float sal,hra,ta,tax;
	printf("Enter your salary : ");
	scanf("%f",&sal);

	hra = (sal)/10;
	ta = (sal)/20;
	sal = sal + hra+ta;
	tax = sal/50;
	sal = sal -tax;
	printf("Your Net Salary is  : %f",sal);
	
}