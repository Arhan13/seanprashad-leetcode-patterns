#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int oneCounter = 0;
        int zeroCounter = 0;
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while (right < n)
        {
            if (nums[right] == 0)
            {
                zeroCounter++;
            }
            else
            {
                oneCounter++;
            }
            while (zeroCounter > 1)
            {
                if (nums[left] == 0)
                {
                    zeroCounter--;
                }
                else
                {
                    oneCounter--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        // As we are allowed to delete only one element (the zero that we found), the maximum length of the subarray will be maxLength - 1.
        return maxLength - 1;
    }
};