// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/957292767/
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
            if (abs(nums[p1]) > abs(nums[p2]))
            {
                ans.push_back(nums[p1] * nums[p1]);
                p1++;
            }
            else if (abs(nums[p1]) < abs(nums[p2]))
            {
                ans.push_back(nums[p2] * nums[p2]);
                p2--;
            }
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