#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int helper(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        int maxLeft = helper(node->left);
        int maxRight = helper(node->right);
        return max(maxLeft, maxRight) + 1;
    }

public:
    int maxDepth(TreeNode *root)
    {
        int ans = helper(root);
        return ans;
    }
};