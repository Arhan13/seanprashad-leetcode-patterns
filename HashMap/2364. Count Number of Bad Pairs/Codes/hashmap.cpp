#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long int ans = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            // As we count the pairs before
            ans += i - ump[nums[i] - i];
            ump[nums[i] - i]++;
        }
        return ans;
    }
};