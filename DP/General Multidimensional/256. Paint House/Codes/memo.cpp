#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &costs, int currHouse, int color, vector<vector<int>> &memo)
    {
        if (currHouse == costs.size())
        {
            return 0;
        }
        // Check memo table
        if (memo[currHouse][color] != -1)
        {
            return memo[currHouse][color];
        }
        int minCost = INT_MAX;
        for (int nextColor = 0; nextColor < 3; nextColor++)
        {
            if (color != nextColor)
            {
                int currCost = costs[currHouse][color] + solve(costs, currHouse + 1, nextColor, memo);
                minCost = min(minCost, currCost);
            }
        }
        return memo[currHouse][color] = minCost;
    }

public:
    int minCost(vector<vector<int>> &costs)
    {
        int ans = INT_MAX;
        vector<vector<int>> memo(costs.size() + 1, vector<int>(3, -1));
        for (int i = 0; i < 3; i++)
        {
            int curr = solve(costs, 0, i, memo);
            ans = min(ans, curr);
        }
        return ans;
    }
};