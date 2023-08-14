#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int currMul = nums[i];
            if (currMul < k)
            {
                count++;
            }
            for (int j = i - 1; j >= 0; j--)
            {
                currMul = currMul * nums[j];
                if (currMul >= k)
                {
                    break;
                }
                count++;
            }
        }
        return count;
    }
};