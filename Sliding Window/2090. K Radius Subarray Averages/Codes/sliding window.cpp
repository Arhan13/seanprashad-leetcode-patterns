#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        if (k > nums.size())
        {
            return ans;
        }
        else if (k == 0)
        {
            return nums;
        }
        long long int sum = -1;
        for (int i = k; i < n - k; i++)
        {
            if (sum == -1)
            {
                long long int tempSum = 0;
                for (int j = 0; j <= i + k; j++)
                {
                    tempSum += nums[j];
                }
                sum = tempSum;
                ans[i] = floor(tempSum / ((2 * k) + 1));
            }
            else
            {
                // Add and remove the old and new element respectively
                sum -= nums[i - k - 1];
                sum += nums[i + k];
                ans[i] = floor(sum / ((2 * k) + 1));
            }
        }
        return ans;
    }
};