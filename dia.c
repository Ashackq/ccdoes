#include <stdio.h>
#include <stdlib.h>

void main()
{
	for(int i=1;i<=9;i+=2)
	{	
		for (int g=1;g<=(9-i)/2;g+=1)
			{
				printf(" ");
			}
		
		for (int f=1;f<=i;f+=1)
		{				
			printf("*");
		}
	
		printf("\n");
	}

	for(int i=9;i>=1;i-=2)
	{	
		if (i == 9)
			{
				continue;
			}	
		else
		{	
		for (int g=1;g<=(9-i)/2;g+=1)
			{
				printf(" ");
			}
		
		for (int f=1;f<=i;f+=1)
		{				
			printf("*");
		}
	
		printf("\n");
	}
	}	
}