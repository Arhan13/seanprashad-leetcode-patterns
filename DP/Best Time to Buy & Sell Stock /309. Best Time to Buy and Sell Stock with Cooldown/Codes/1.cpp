#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp(vector<int> prices, bool isBuy, int currentIndex)
    {
        if (currentIndex >= prices.size())
        {
            return 0;
        }
        int ans = 0;
        ans = dp(prices, isBuy, currentIndex + 1);
        if (isBuy)
        {
            ans = max(ans, -prices[currentIndex] + dp(prices, false, currentIndex + 1));
        }
        else
        {
            ans = max(ans, prices[currentIndex] + dp(prices, true, currentIndex + 2));
        }
        return ans;
    }
    int maxProfit(vector<int> &prices)
    {
        return dp(prices, true, 0);
    }
};