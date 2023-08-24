// Similar to coin change

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n, int currAmount, vector<vector<int>> &memo)
    {
        if (n <= 0)
        {
            return INT_MAX - 100;
        }
        if (currAmount == 0)
        {
            return 0;
        }
        if (memo[n][currAmount] != -1)
        {
            return memo[n][currAmount];
        }
        // include
        if (pow(n, 2) <= currAmount)
        {
            memo[n][currAmount] = min(1 + solve(n, currAmount - pow(n, 2), memo), solve(n - 1, currAmount, memo));
        }
        else
        {
            memo[n][currAmount] = solve(n - 1, currAmount, memo);
        }
        return memo[n][currAmount];
    }

public:
    int numSquares(int n)
    {
        int upperLimit = sqrt(n) + 1;
        vector<vector<int>> memo(upperLimit + 1, vector<int>(n + 1, -1));
        int res = solve(upperLimit, n, memo);
        return res == (INT_MAX - 100) ? -1 : res;
    }
};