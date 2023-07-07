#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
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
            while (zeroCounter > k)
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
        return maxLength;
    }
};