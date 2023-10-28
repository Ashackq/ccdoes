#include <stdio.h>

void main()
{	
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
}