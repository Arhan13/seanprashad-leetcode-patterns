#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums.at(right) != nums.at(left))
            {
                left++;
                nums.at(left) = nums.at(right);
            }
        }
        return left + 1;
    }
};