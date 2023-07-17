#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void generateIntervals(vector<vector<int>> &intervals, vector<vector<int>> &ans)
    {
        for (vector<int> interval : intervals)
        {
            if (ans.size() == 0)
            {
                ans.push_back(interval);
            }
            else
            {
                vector<int> top = ans[ans.size() - 1];
                if (top[1] >= interval[0])
                {
                    ans.pop_back();
                    ans.push_back(vector<int>{top[0], max(interval[1], top[1])});
                }
                else
                {
                    ans.push_back(interval);
                }
            }
        }
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> ans;
        generateIntervals(intervals, ans);
        return ans;
    }
};