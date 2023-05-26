#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> nums, vector<int> &path)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (auto x : nums)
        {
            if (find(path.begin(), path.end(), x) == path.end())
            {
                path.push_back(x);
                dfs(ans, nums, path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (auto x : nums)
        {
            vector<int> path;
            path.push_back(x);
            dfs(ans, nums, path);
            path.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = s.permute(nums);
    for (auto p : permutations)
    {
        for (auto x : p)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}