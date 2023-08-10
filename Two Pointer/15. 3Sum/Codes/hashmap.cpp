#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> tempAns;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            unordered_map<int, int> ump;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int itemToFind = target - nums[j];
                if (ump.count(itemToFind) > 0)
                {
                    vector<int> _3Sum({nums[i], nums[j], itemToFind});
                    tempAns.insert(_3Sum);
                    while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                }
                else
                {
                    ump[nums[j]] = j;
                }
            }
        }
        vector<vector<int>> ans(tempAns.begin(), tempAns.end());
        return ans;
    }
};