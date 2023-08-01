#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                // Find the lower bound for nums[i]
                int ind =
                    lower_bound(
                        temp.begin(),
                        temp.end(),
                        nums[i]) -
                    temp.begin();
                temp[ind] = nums[i];
            }
        }
        // The temp array here is not the LIS, but is only used for getting the length of LIS
        return temp.size();
    }
};