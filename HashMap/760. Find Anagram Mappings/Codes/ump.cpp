#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            ump[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = ump[nums1[i]];
        }
        return ans;
    }
};