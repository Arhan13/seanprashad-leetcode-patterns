#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &prices, bool isBuy, int currentIndex, int k, vector<vector<vector<int>>> &memo)
    {
        if (currentIndex >= prices.size())
        {
            return 0;
        }
        if (k == 0)
        {
            return 0;
        }
        if (memo[currentIndex][isBuy ? 1 : 0][k] != -1)
        {
            return memo[currentIndex][isBuy ? 1 : 0][k];
        }
        int currProfit = solve(prices, isBuy, currentIndex + 1, k, memo);
        if (isBuy)
        {
            currProfit = max(currProfit, -prices[currentIndex] + solve(prices, false, currentIndex + 1, k, memo));
        }
        else
        {
            currProfit = max(currProfit, prices[currentIndex] + solve(prices, true, currentIndex + 1, k - 1, memo));
        }
        memo[currentIndex][isBuy ? 1 : 0][k] = currProfit;
        return currProfit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // Seq - currentIndex, isBuy, k
        vector<vector<vector<int>>> memo(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, true, 0, 2, memo);
    }
};