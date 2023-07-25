#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &matrix, int currentLevel, int currentIndex, vector<vector<int>> &memo)
    {
        if (currentLevel >= matrix.size() || currentIndex >= matrix.size())
        {
            return 0;
        }
        if (memo[currentLevel][currentIndex] != INT_MAX)
        {
            return memo[currentLevel][currentIndex];
        }
        int _minSum = INT_MAX;
        if (currentIndex == 0)
        {
            _minSum = matrix[currentLevel][currentIndex] + min(solve(matrix, currentLevel + 1, currentIndex, memo), solve(matrix, currentLevel + 1, currentIndex + 1, memo));
        }
        else if (currentIndex == matrix.size() - 1)
        {
            _minSum = matrix[currentLevel][currentIndex] + min(solve(matrix, currentLevel + 1, currentIndex - 1, memo), solve(matrix, currentLevel + 1, currentIndex, memo));
        }
        else
        {
            _minSum = matrix[currentLevel][currentIndex] + min(solve(matrix, currentLevel + 1, currentIndex - 1, memo), min(solve(matrix, currentLevel + 1, currentIndex, memo), solve(matrix, currentLevel + 1, currentIndex + 1, memo)));
        }
        memo[currentLevel][currentIndex] = _minSum;
        return memo[currentLevel][currentIndex];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> memo(matrix.size() + 1, vector<int>(matrix.size() + 1, INT_MAX));
        int minSum = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
        {
            minSum = min(minSum, solve(matrix, 0, i, memo));
        }
        return minSum;
    }
};