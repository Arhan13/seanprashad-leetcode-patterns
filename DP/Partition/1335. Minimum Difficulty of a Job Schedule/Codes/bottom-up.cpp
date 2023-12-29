#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;
    vector<int> jd;
    int n = 0;
    int dfs(int i, int d)
    { // i is the current job index
        if (dp[i][d] != INT_MAX)
        {
            return dp[i][d];
        }
        // If there is only one job left then we need pick the maximum job from the remaining jobs
        if (d == 1)
        {
            // Get max element from that index i
            return dp[i][d] = *max_element(jd.begin() + i, jd.end());
        }
        int maxInDivision = INT_MIN, res = INT_MAX;
        for (int j = i; j < (n - (d - 1)); j++)
        { // so that there are atleast d-1 jobs left for the d-1 days
            maxInDivision = max(maxInDivision, jd[j]);
            res = min(res, maxInDivision + dfs(j + 1, d - 1));
        }
        return dp[i][d] = res;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        jd = jobDifficulty;
        dp.resize(n + 1, vector<int>(d + 1, INT_MAX));
        return dfs(0, d);
    }
};