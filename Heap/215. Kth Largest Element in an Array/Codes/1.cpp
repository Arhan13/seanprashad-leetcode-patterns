#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // We need a min heap
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < nums.size(); i++)
        {
            minH.push(nums[i]);
            if (minH.size() > k)
            {
                minH.pop();
            }
        }
        return minH.top();
    }
};