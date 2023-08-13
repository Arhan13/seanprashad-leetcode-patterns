#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (auto num : nums)
        {
            ump[num]++;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        for (int i = 1; i < maxNum; i++)
        {
            if (!ump.count(i))
            {
                return i;
            }
        }
        return ump.count(1) > 0 ? maxNum + 1 : 1;
    }
};