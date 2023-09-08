#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &costs, int houses, int colors, int currHouse, int color, vector<vector<int>> &memo)
    {
        if (currHouse == houses)
        {
            return 0;
        }
        if (memo[currHouse][color] != -1)
        {
            return memo[currHouse][color];
        }
        int minCost = INT_MAX;
        for (int i = 0; i < colors; i++)
        {
            if (i != color)
            {
                int currCost = costs[currHouse][color] + solve(costs, houses, colors, currHouse + 1, i, memo);
                minCost = min(minCost, currCost);
            }
        }
        return memo[currHouse][color] = minCost;
    }

public:
    int minCostII(vector<vector<int>> &costs)
    {
        int houses = costs.size();
        int colors = costs[0].size();
        vector<vector<int>> memo(houses + 1, vector<int>(colors, -1));
        int minCost = INT_MAX;
        for (int i = 0; i < colors; i++)
        {
            int currCost = solve(costs, houses, colors, 0, i, memo);
            minCost = min(minCost, currCost);
        }
        return minCost;
    }
};