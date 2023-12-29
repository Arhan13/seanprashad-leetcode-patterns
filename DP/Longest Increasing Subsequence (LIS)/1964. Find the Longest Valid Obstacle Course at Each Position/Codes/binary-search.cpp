#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> lis(n, 0), dp = {};
        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            if (index == dp.size())
            {
                dp.push_back(obstacles[i]);
                lis[i] = dp.size();
            }
            else
            {
                dp[index] = obstacles[i];
                lis[i] = index + 1;
            }
        }
        return lis;
    }
};