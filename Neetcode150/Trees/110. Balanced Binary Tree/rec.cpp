#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int helper(TreeNode *node)
    {
        if (!node)
        {
            return true;
        }
        int leftHeight = helper(node->left);
        int rightHeight = helper(node->right);
        if (leftHeight == -1 || rightHeight == -1)
        {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return helper(root) == -1 ? false : true;
    }
};