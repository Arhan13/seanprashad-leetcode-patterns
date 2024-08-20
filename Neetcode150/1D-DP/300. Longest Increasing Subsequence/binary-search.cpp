#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp = {};
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            int currMaxInSeq = temp.back();
            if (nums[i] > currMaxInSeq)
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};