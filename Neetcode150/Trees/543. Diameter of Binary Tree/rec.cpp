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
    int helper(TreeNode *node, int &maxi)
    {
        if (!node)
        {
            return 0;
        }
        int leftSum = helper(node->left, maxi);
        int rightSum = helper(node->right, maxi);
        maxi = max(maxi, leftSum + rightSum + 1);
        return max(leftSum, rightSum) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi - 1; // converting the count of nodes to the count of edges
    }
};