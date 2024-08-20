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
    TreeNode *findLCA(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (!node)
        {
            return NULL;
        }
        if (p->val < node->val && q->val < node->val)
        {
            return findLCA(node->left, p, q);
        }
        else if (p->val > node->val && q->val > node->val)
        {
            return findLCA(node->right, p, q);
        }
        else
        {
            return node;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return findLCA(root, p, q);
    }
};