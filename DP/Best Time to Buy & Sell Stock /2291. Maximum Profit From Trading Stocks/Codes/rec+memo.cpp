#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &present, vector<int> &future, int currentBudget, int currentIndex, vector<vector<int>> &memo)
    {
        if (currentBudget < 0 || currentIndex >= present.size())
        {
            return 0;
        }
        if (memo[currentIndex][currentBudget] != -1)
        {
            return memo[currentIndex][currentBudget];
        }
        // No we have two choices, we either -
        int makeTrade = 0, doesNotMakeTrade = 0;
        // 1. Make the trade
        if (currentBudget >= present[currentIndex] && present[currentIndex] < future[currentIndex])
        {
            makeTrade = solve(present, future, currentBudget - present[currentIndex], currentIndex + 1, memo) + (future[currentIndex] - present[currentIndex]);
        }
        // 2. We don't make the trade
        doesNotMakeTrade = solve(present, future, currentBudget, currentIndex + 1, memo);
        memo[currentIndex][currentBudget] = max(makeTrade, doesNotMakeTrade);
        return memo[currentIndex][currentBudget];
    }

public:
    int maximumProfit(vector<int> &present, vector<int> &future, int budget)
    {
        vector<vector<int>> memo(present.size() + 1, vector<int>(budget + 1, -1));
        return solve(present, future, budget, 0, memo);
    }
};