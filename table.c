#include <stdio.h>

void main()
{

	int c ,n;
	printf("Enter a number: ");
	scanf("%d",&n);

	c = 1;
	
	while (c <= -12){
		printf("%d * %d = %d \n",n,c,c*n);
		c += 1;

	}
}