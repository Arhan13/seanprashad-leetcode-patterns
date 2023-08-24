#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long solve(vector<vector<int>> &q, int currentIndex, vector<long long> &memo)
    {
        if (currentIndex >= q.size())
        {
            return 0;
        }
        if (memo[currentIndex] != -1)
        {
            return memo[currentIndex];
        }
        int points = q[currentIndex][0];
        int skips = q[currentIndex][1];

        long long ans = max(solve(q, currentIndex + 1, memo), points + solve(q, currentIndex + skips + 1, memo));
        return memo[currentIndex] = ans;
    }

public:
    long long mostPoints(vector<vector<int>> &q)
    {
        vector<long long> memo(q.size() + 1, -1);
        return solve(q, 0, memo);
    }
};