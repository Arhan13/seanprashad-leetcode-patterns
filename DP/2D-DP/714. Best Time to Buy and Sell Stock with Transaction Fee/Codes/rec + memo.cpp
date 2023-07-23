#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int _fee;
    vector<int> _prices;

private:
    int solve(bool isBuy, int currentIndex, vector<vector<int>> &memo)
    {
        if (currentIndex >= _prices.size())
        {
            return 0;
        }
        if (memo[currentIndex][isBuy] != -1)
        {
            return memo[currentIndex][isBuy];
        }
        int currProfit = max(0, solve(isBuy, currentIndex + 1, memo));
        if (isBuy)
        {
            currProfit = max(currProfit, -_prices[currentIndex] + solve(false, currentIndex + 1, memo));
        }
        else
        {
            currProfit = max(currProfit, _prices[currentIndex] - _fee + solve(true, currentIndex + 1, memo));
        }
        memo[currentIndex][isBuy] = currProfit;
        return currProfit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        _fee = fee;
        _prices = prices;
        vector<vector<int>> memo(_prices.size() + 1, vector<int>(2, -1));
        return solve(true, 0, memo);
    }
};