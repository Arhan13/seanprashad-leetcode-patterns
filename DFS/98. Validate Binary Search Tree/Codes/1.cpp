#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool dfs(TreeNode *root, long long min, long long max)
    {
        if (!root)
        {
            return true;
        }
        if (!(min < root->val && root->val < max))
        {
            return false;
        }
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root)
    {
        // NULL root is a valid BST
        if (!root)
        {
            return true;
        }
        // DFS on left and right side
        return dfs(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};