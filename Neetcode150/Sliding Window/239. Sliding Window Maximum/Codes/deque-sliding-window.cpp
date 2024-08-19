#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans = {};
        if (n == 0)
        {
            return ans;
        }
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            // Remove the element that is outside the window
            if (dq.size() > 0 && dq.front() == i - k)
            {
                dq.pop_front();
            }
            // Remove the elements smaller than the current element
            while (dq.size() > 0 && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // Add the maximum element to our response array
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};