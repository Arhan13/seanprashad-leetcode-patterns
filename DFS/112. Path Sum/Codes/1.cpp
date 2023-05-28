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
    void dfs(TreeNode *root, vector<int> path, vector<int> &sums)
    {
        // Child Node case - sum up all the paths from the root to the child node, then store it in sums
        if (root && root->left == nullptr && root->right == nullptr)
        {
            path.push_back(root->val);
            int tempSum = 0;
            for (auto sum : path)
            {
                tempSum += sum;
            }
            sums.push_back(tempSum);
            return;
        }
        if (root && root->left)
        {
            vector<int> path_copy(path);
            path_copy.push_back(root->val);
            dfs(root->left, path_copy, sums);
        }
        if (root && root->right)
        {
            vector<int> path_copy(path);
            path_copy.push_back(root->val);
            dfs(root->right, path_copy, sums);
        }
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        vector<int> sums;
        dfs(root, {}, sums);
        int ans = 0;
        for (auto sum : sums)
        {
            if (sum == targetSum)
            {
                return true;
            }
        }
        return false;
    }
};