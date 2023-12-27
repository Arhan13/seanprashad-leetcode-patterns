#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        unordered_map<int, pair<int, int>> dp;
        int lenLIS = 0;
        int numberOfLIS = 0;

        // Lets start at the last index of nums
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int maxLenLIS = 1;
            int maxCountOfLIS = 1;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    int lengthOfLIS = 0;
                    int countOfLIS = 0;
                    pair<int, int> ele = dp[j];
                    lengthOfLIS = ele.first;
                    countOfLIS = ele.second;

                    if (lengthOfLIS + 1 > maxLenLIS)
                    {
                        maxLenLIS = lengthOfLIS + 1;
                        maxCountOfLIS = countOfLIS;
                    }
                    else if (lengthOfLIS + 1 == maxLenLIS)
                    {
                        maxCountOfLIS += countOfLIS;
                    }
                }
            }

            if (maxLenLIS > lenLIS)
            {
                lenLIS = maxLenLIS;
                numberOfLIS = maxCountOfLIS;
            }
            else if (maxLenLIS == lenLIS)
            {
                numberOfLIS += maxCountOfLIS;
            }

            dp[i] = make_pair(maxLenLIS, maxCountOfLIS);
        }

        return numberOfLIS;
    }
};