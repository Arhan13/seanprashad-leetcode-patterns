#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
// Time Complexity: O(n*amount)
// Space Complexity: O(n*amount)
// n: size of coins array
// amount: given amount
// INT_MAX - 1 is used to avoid overflow

class Solution
{
public:
    int unboundKnapsack(vector<int> &coins, int n, int currentAmount, vector<vector<int>> &memo)
    {
        if (n <= 0)
        {
            return INT_MAX - 1;
        }
        if (currentAmount == 0)
        {
            return 0;
        }
        if (memo[n][currentAmount] != -1)
        {
            return memo[n][currentAmount];
        }
        // include
        if (coins[n - 1] <= currentAmount)
        {
            memo[n][currentAmount] = min(1 + unboundKnapsack(coins, n, currentAmount - coins[n - 1], memo), unboundKnapsack(coins, n - 1, currentAmount, memo));
            return memo[n][currentAmount];
        }
        // exclude
        else
        {
            memo[n][currentAmount] = unboundKnapsack(coins, n - 1, currentAmount, memo);
            return memo[n][currentAmount];
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        // Dont suggest
        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        int res = unboundKnapsack(coins, n, amount, memo);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};
