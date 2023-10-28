#include <stdio.h>

int main()
{
	int i, j, k;

	i = 1;

	while (i <= 5)
	{
		j = 1;
		while (j < i)
		{
			printf(" ");
			j++;
		}

		k = 6 - i;
		while (k != 0)
		{
			printf("%d ", k);
			k--;
		}
		printf("\n");
		i++;
	}
}