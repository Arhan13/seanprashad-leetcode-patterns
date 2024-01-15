#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums.at(fast) != 0)
            {
                int tempSlow = nums.at(slow);
                nums.at(slow) = nums.at(fast);
                nums.at(fast) = tempSlow;
                slow++;
            }
            fast++;
        }
    }
};