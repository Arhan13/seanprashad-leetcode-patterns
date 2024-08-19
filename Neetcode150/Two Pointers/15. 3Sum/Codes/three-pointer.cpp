#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans = {};
        if (n < 3)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        // Now we will have 3 points, i, j, k
        for (int i = 0; i < n - 2; i++)
        {
            // Here i is the smallest elements so it should be negative at the least
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // Skip repeated j's
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    // Increment j
                    j++;
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};