#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        const int minSum = getMinSum(mat);
        if (minSum >= target)
        {
            return minSum - target;
        }
        const int maxSum = getMaxSum(mat);
        dp.resize(mat.size(), vector<int>(maxSum + 1, -1));
        return minimizeTheDifference(mat, 0, 0, target);
    }

private:
    vector<vector<int>> dp;
    int minimizeTheDifference(const vector<vector<int>> &mat, int i, int currentSum, int target)
    {
        if (i == mat.size())
        {
            return abs(currentSum - target);
        }
        if (dp[i][currentSum] != -1)
        {
            return dp[i][currentSum];
        }
        int ans = INT_MAX;
        for (const int num : mat[i])
        {
            ans = min(ans, minimizeTheDifference(mat, i + 1, currentSum + num, target));
        }
        return dp[i][currentSum] = ans;
    }
    int getMinSum(const vector<vector<int>> &mat)
    {
        return accumulate(begin(mat), end(mat), 0,
                          [](int subtotal, const vector<int> &row)
                          {
                              return subtotal + *min_element(begin(row), end(row));
                          });
    }
    int getMaxSum(const vector<vector<int>> &mat)
    {
        return accumulate(begin(mat), end(mat), 0,
                          [](int subtotal, const vector<int> &row)
                          {
                              return subtotal + *max_element(begin(row), end(row));
                          });
    }
};