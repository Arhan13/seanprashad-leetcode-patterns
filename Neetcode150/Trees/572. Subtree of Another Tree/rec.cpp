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
    bool isIdentical(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2)
        {
            return true;
        }
        if (!node1 || !node2)
        {
            return false;
        }
        if (node1->val != node2->val)
        {
            return false;
        }
        return (
            isIdentical(node1->left, node2->left) &&
            isIdentical(node1->right, node2->right));
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
        {
            return true;
        }
        if (!root || !subRoot)
        {
            return false;
        }
        if (isIdentical(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};