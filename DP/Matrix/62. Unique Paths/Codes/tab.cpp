#include <bits/stdc++.h>
using namespace std;

// Focus of the word "paths"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Initialize the DP table with 1's
        /*
        The remaining rows are filled with 1 because we can only move down or right in the grid. Therefore, there is only one way to reach any cell in the last row or last column. For example, to reach the cell at (i, n-1), we can only move down from the cell at (i-1, n-1). Similarly, to reach the cell at (m-1, j), we can only move right from the cell at (m-1, j-1). Therefore, the number of unique paths to reach any cell in the last row or last column is 1.
        */
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Traverse the DP table from bottom to top and right to left
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                // Update the DP table using the recurrence relation
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        // Return the result
        return dp[0][0];
    }
};