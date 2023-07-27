#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> ump1;
        for (auto x : nums1)
        {
            ump1[x]++;
        }
        for (auto x : nums2)
        {
            if (ump1[x] > 0)
            {
                ans.push_back(x);
                ump1[x]--;
            }
        }
        return ans;
    }
};