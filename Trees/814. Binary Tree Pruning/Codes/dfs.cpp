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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    bool hasOne(TreeNode *node)
    {
        if (!node)
        {
            return false;
        }
        if (node->val == 1)
        {
            return true;
        }
        else
        {
            return hasOne(node->left) || hasOne(node->right);
        }
        return false;
    }
    TreeNode *dfsHelper(TreeNode *node)
    {
        if (!node)
        {
            return nullptr;
        }
        if (!hasOne(node))
        {
            return nullptr;
        }
        node->left = dfsHelper(node->left);
        node->right = dfsHelper(node->right);
        return node;
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        return dfsHelper(root);
    }
};