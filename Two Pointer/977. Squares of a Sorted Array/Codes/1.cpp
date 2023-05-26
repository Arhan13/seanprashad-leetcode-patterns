#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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