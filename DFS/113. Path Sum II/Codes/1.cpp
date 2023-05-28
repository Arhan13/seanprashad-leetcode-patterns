#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> &path, TreeNode *root, int targetSum)
    {
        if (root && root->right == nullptr && root->left == nullptr)
        {
            path.push_back(root->val);
            int tempSum = 0;
            for (auto x : path)
            {
                tempSum += x;
            }
            if (tempSum == targetSum)
            {
                ans.push_back(path);
            }
            return;
        }
        if (root && root->left)
        {
            vector<int> copy_path(path);
            copy_path.push_back(root->val);
            dfs(ans, copy_path, root->left, targetSum);
        }
        if (root && root->right)
        {
            vector<int> copy_path(path);
            copy_path.push_back(root->val);
            dfs(ans, copy_path, root->right, targetSum);
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, root, targetSum);
        return ans;
    }
};