#include <stdio.h>

void main()
{

	int c ,n,l;
	c = 1;
	while (c<11){
		if (c==1){
			printf("The number %d is : ",c);	
			scanf("%d",&l);	
		}
		else{
			printf("The number %d is : ",c);	
			scanf("%d",&n);
			if (n>l){
				l = n;
			}
		}

		c += 1;
	}
	printf("The largest number is - %d \n",l );
}