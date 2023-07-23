#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currMin = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < currMin)
            {
                currMin = prices[i];
            }
            if (prices[i] - currMin > maxProfit)
            {
                maxProfit = prices[i] - currMin;
            }
        }
        return maxProfit;
    }
};