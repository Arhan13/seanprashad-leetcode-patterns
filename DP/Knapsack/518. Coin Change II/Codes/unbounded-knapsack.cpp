#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int currentIndex, int currAmountLeft, vector<int> &coins, vector<vector<int>> &memo)
    {
        if (currAmountLeft == 0)
        {
            return 1;
        }
        if (currentIndex == coins.size())
        {
            return 0;
        }
        if (memo[currentIndex][currAmountLeft] != -1)
        {
            return memo[currentIndex][currAmountLeft];
        }
        if (coins[currentIndex] > currAmountLeft)
        {
            return memo[currentIndex][currAmountLeft] = solve(currentIndex + 1, currAmountLeft, coins, memo);
        }
        // We can either choose the coin or skip the coin
        int pickCoin = solve(currentIndex, currAmountLeft - coins[currentIndex], coins, memo);
        int dontPickCoin = solve(currentIndex + 1, currAmountLeft, coins, memo);
        return memo[currentIndex][currAmountLeft] = pickCoin + dontPickCoin;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, memo);
    }
};