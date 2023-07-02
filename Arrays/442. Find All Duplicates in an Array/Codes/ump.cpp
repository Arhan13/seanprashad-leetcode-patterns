#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        vector<int> ans;
        for (auto x : nums)
        {
            ump[x]++;
        }
        for (auto x : ump)
        {
            if (x.second == 2)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};