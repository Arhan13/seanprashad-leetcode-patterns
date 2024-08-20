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
    void invertHelper(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        TreeNode *temp = node->right;
        node->right = node->left;
        node->left = temp;
        if (node->right)
        {
            invertHelper(node->right);
        }
        if (node->left)
        {
            invertHelper(node->left);
        }
        return;
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        invertHelper(root);
        return root;
    }
};