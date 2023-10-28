#include <stdio.h>

void main()
{

	int c ,n,nc;
	scanf("%d",&n);
	c = 1;
	 
	while (c<=n){
		nc = n;
		if (c== (1 && n)){
			while (nc != 0){
				printf("*");
				nc-=1;
			}
		}
		else{
			printf("*");
			while ((nc - 2) != 0){
				printf(" ");
				nc -= 1;
			}
			printf("*");
		}
		c += 1;
	}
	
}