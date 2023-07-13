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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // What are the cases
        // If the node is null we will return the root itself
        if (!root)
        {
            return root;
        }
        // If the node is either p or q, we will return it as it is, because its a node above either and will represent a ancestor
        if (root == p || root == q)
        {
            return root;
        }
        // Now if node is neither p or q
        // We will scan its children
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // If both of them are valid then we will return the exisiting node
        if (left && right)
        {
            return root;
        }
        // If left is valid then we will return the left node
        if (left && !right)
        {
            return left;
        }
        // If right is valid then we will return the right node
        if (!left && right)
        {
            return right;
        }
        // Else we will return null as we did not yield anything
        return nullptr;
    }
};