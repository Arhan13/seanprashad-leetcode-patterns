// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/957292767/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        int N = nums.size();
        int p1 = 0;
        int p2 = N - 1;
        while (p1 <= p2)
        {
            // if the absolute value of the number at p1 is greater than the absolute value of the number at p2
            if (abs(nums[p1]) > abs(nums[p2]))
            {
                ans.push_back(nums[p1] * nums[p1]);
                p1++;
            }
            // if the absolute value of the number at p1 is less than the absolute value of the number at p2
            else if (abs(nums[p1]) < abs(nums[p2]))
            {
                ans.push_back(nums[p2] * nums[p2]);
                p2--;
            }
            // if the absolute value of the number at p1 is equal to the absolute value of the number at p2
            else if (abs(nums[p1]) == abs(nums[p2]))
            {
                ans.push_back(nums[p1] * nums[p1]);
                p1++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> sortedSquares = s.sortedSquares(nums);
    for (auto x : sortedSquares)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}