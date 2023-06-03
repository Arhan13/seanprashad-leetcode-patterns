#include <bits/stdc++.h>
using namespace std;

// DP Pattern: 2D DP - Grid
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// m: number of rows
// n: number of columns
// Which pattern of DP is this?
// This is a 2D DP problem. We can move down or right. We can't move up or left.
// We can only move down or right. We can't move up or left.
// We can move down, right or diagonally.
// What is the state of DP?
// The state of DP is the current position (x, y).
// What is the base case?
// If we reach the bottom right corner, we return 1.
// What are the decisions we can make at each state?
// We can move down or right.
// What is the recurrence relation?
// dp(x, y) = dp(x + 1, y) + dp(x, y + 1)
// What is the order of traversal?
// We can traverse in any order. We can start from the top left corner or the bottom right corner.
// We can start from the top left corner or the bottom right corner.

class Solution
{
public:
    int dp(int m, int n, int x, int y, vector<vector<int>> &memo)
    {
        if (x == m - 1 && y == n - 1)
        {
            return 1;
        }
        if (memo[x][y] != -1)
        {
            return memo[x][y];
        }
        int ans = 0;
        // We can only move down
        if (x + 1 <= m && y + 1 > n)
        {
            ans = dp(m, n, x + 1, y, memo);
        }
        // We can only move to the right
        else if (x + 1 > m && y + 1 <= n)
        {
            ans = dp(m, n, x, y + 1, memo);
        }
        // We can move down and right
        else if (x + 1 <= m && y + 1 <= n)
        {
            ans = dp(m, n, x + 1, y, memo) + dp(m, n, x, y + 1, memo);
        }
        return memo[x][y] = ans;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dp(m, n, 0, 0, memo);
    }
};