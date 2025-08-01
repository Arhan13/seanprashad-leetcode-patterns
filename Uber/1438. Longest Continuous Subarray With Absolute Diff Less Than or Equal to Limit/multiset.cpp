#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int left = 0;
        int maxEle = 0, minEle = 0, maxLen = 0;
        multiset<int> ms;
        for (int right = 0; right < n; ++right)
        {
            ms.insert(nums[right]);
            while (abs(*ms.rbegin() - *ms.begin()) > limit)
            {
                ms.erase(ms.find(nums[left]));
                ++left;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};