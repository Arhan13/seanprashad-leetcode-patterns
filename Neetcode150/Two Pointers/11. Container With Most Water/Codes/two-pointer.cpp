#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC - O(n)
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = INT_MIN;
        while (left < right)
        {
            int currVal = min(height[left], height[right]) * (right - left);
            ans = max(ans, currVal);
            if (height[left] < height[right])
            {
                left++;
            }
            else if (height[left] > height[left])
            {
                right--;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};