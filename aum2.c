
#include <stdio.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))

#define min(x, y) (((x) < (y)) ? (x) : (y))


int maxProfit(int price[], int start, int end)
{


	if (end <= start)
		return 0;


	int profit = 0;

	for (int i = start; i < end; i++) {


		for (int j = i + 1; j <= end; j++) {

			if (price[j] > price[i]) {

				int curr_profit
					= price[j] - price[i]
					;

				profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}


int main()
{
	int price[1000],i,n;
	scanf("%d", &n);
    
    for(i=0; i<n; i++)
        scanf("%d", &price[i]);
	
	printf("%d", maxProfit(price, 0, n - 1));
	return 0;
}
