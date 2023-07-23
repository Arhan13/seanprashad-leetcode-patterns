#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*k)
// Space Complexity: O(n*k)

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (k >= n / 2)
        {
            int maxProfit = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }
        if (k <= 0)
        {
            return 0;
        }
        vector<vector<int>> tab(k + 1, vector<int>(n + 1, 0));
        int buyMaxVal = 0;
        for (int currK = 1; currK <= k; currK++)
        {
            int stuff = tab[currK - 1][0] - prices[0];
            for (int currDay = 0; currDay < n; currDay++)
            {
                int currStuff = -prices[currDay] + tab[currK - 1][currDay];
                stuff = max(stuff, currStuff);
                tab[currK][currDay] = max(
                    // If we do not do anything and just let k txns happen till the prvious block
                    tab[currK][currDay > 0 ? currDay - 1 : 0],
                    prices[currDay] + stuff);
            }
        }
        return tab[k][n - 1];
    }
};