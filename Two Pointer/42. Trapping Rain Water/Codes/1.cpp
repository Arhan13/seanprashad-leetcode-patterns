#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: Precompute the maximum height of the left and right side of the current index.
//           Then, the amount of water that can be trapped at the current index is the minimum of the maximum height of the left and right side minus the height of the current index.
//           Add the amount of water that can be trapped at the current index to the answer.
//           Return the answer.

// Intuition: The amount of water that can be trapped at the current index is the minimum of the maximum height of the left and right side minus the height of the current index.
//            The maximum height of the left and right side of the current index can be precomputed.
//            Then, the amount of water that can be trapped at the current index can be calculated in constant time.
//            Add the amount of water that can be trapped at the current index to the answer.
//            Return the answer.

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftPreCompute(n, 0);
        vector<int> rightPreCompute(n, 0);
        int ans = 0;
        leftPreCompute[0] = height[0];
        rightPreCompute[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            if (height[i] > leftPreCompute[i - 1])
            {
                leftPreCompute[i] = height[i];
            }
            else
            {
                leftPreCompute[i] = leftPreCompute[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (height[i] > rightPreCompute[i + 1])
            {
                rightPreCompute[i] = height[i];
            }
            else
            {
                rightPreCompute[i] = rightPreCompute[i + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans += min(leftPreCompute[i], rightPreCompute[i]) - height[i];
        }

        return ans;
    }
};