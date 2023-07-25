#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &triangle, int currentLevel, int currentIndex, vector<vector<int>> &memo)
    {
        if (currentLevel >= triangle.size() || currentIndex >= triangle[currentLevel].size())
        {
            return 0;
        }
        if (memo[currentLevel][currentIndex] != -1)
        {
            return memo[currentLevel][currentIndex];
        }
        int minSum = triangle[currentLevel][currentIndex] + min(solve(triangle, currentLevel + 1, currentIndex, memo), solve(triangle, currentLevel + 1, currentIndex + 1, memo));
        memo[currentLevel][currentIndex] = minSum;
        return minSum;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> memo(triangle.size() + 1, vector<int>(triangle[triangle.size() - 1].size() + 1, -1));
        return solve(triangle, 0, 0, memo);
    }
};