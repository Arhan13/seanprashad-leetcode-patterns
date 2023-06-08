#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> LISLength(nums.size(), 1);
        vector<int> LISCount(nums.size(), 1);
        // We need to iterate from n-1 to 0
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int LISLengthI = 1, LISCountI = 1;
            for (int j = i + 1; j <= nums.size() - 1; j++)
            {
                int LISLengthJ = LISLength[j];
                int LISCountJ = LISCount[j];
                if (nums[j] > nums[i])
                {
                    if (LISLengthJ + 1 > LISLengthI)
                    {
                        LISLengthI = LISLengthJ + 1;
                        LISCountI = LISCountJ;
                    }
                    else if (LISLengthJ + 1 == LISLengthI)
                    {
                        LISCountI += LISCountJ;
                    }
                }
            }
            LISLength[i] = LISLengthI;
            LISCount[i] = LISCountI;
        }
        int maxLength = *max_element(LISLength.begin(), LISLength.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (LISLength[i] == maxLength)
            {
                count += LISCount[i];
            }
        }
        return count;
    }
};