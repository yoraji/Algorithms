#include <stdio.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0)
	    return 0;
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = (dp[j] < dp[j - coins[i]] + 1) ? dp[j] : (dp[j - coins[i]] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main()
{
	int coins[] = {1,2,5};
	int coinsSize = sizeof(coins) / sizeof(coins[0]);
	int amount = 11;
	int result = coinChange(coins, coinsSize, amount);
	if(result == -1)
	{
		printf("It is not possible to make up the amount %d with the given coins.\n",amount, result);
	}	
	else{
		printf("Minimum number of coins required to make up %d: %d\n", amount, result);
	}
	return 0;
}
