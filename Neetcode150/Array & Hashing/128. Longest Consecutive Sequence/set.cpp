#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int maxStreak = 1;
        int n = nums.size();
        unordered_set<int> s;
        for (auto num : nums)
        {
            s.insert(num);
        }
        for (int i = 0; i < n; i++)
        {
            int currNum = nums[i];
            if (s.count(currNum - 1) == 0)
            {
                int currStreak = 1;
                while (s.count(currNum + 1) > 0)
                {
                    currStreak += 1;
                    currNum += 1;
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};