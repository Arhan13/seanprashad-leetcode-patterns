#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp(vector<int> prices, bool isBuy, int currentIndex, vector<vector<int>> &memo)
    {
        if (currentIndex >= prices.size())
        {
            return 0;
        }
        if (memo[isBuy][currentIndex] != -1)
        {
            return memo[isBuy][currentIndex];
        }
        int ans = 0;
        ans = dp(prices, isBuy, currentIndex + 1, memo);
        if (isBuy)
        {
            ans = max(ans, -prices[currentIndex] + dp(prices, false, currentIndex + 1, memo));
        }
        else
        {
            ans = max(ans, prices[currentIndex] + dp(prices, true, currentIndex + 2, memo));
        }
        memo[isBuy][currentIndex] = ans;
        return ans;
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> memo(2, vector<int>(prices.size() + 1, -1));
        return dp(prices, true, 0, memo);
    }
};