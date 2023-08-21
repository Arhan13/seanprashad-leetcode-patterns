#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> ans = {};
        int start = rounds[0];
        int end = rounds.back();
        if (start <= end)
        {
            for (int i = start; i <= end; i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            for (int i = 1; i <= end; i++)
            {
                ans.push_back(i);
            }
            for (int i = start; i <= n; i++)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};