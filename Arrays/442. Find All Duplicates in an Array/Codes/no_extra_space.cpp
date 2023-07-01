#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (auto x : nums)
        {
            if (nums[abs(x) - 1] < 0)
            { // seen before that why it is marked negative
                ans.push_back(abs(x));
            }
            nums[abs(x) - 1] *= -1;
        }
        return ans;
    }
};