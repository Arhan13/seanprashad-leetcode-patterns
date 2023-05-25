// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/957277883/
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};