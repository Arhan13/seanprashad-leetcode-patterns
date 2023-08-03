#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        long long int ans = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        for (auto x : ump)
        {
            int count = x.second;
            ans += count * (count - 1) / 2;
        }
        return ans;
    }
};