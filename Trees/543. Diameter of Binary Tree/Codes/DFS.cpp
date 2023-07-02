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
public:
    int diameterOfBinaryTreeHelper(TreeNode *node, int &maxi)
    {
        if (!node)
        {
            return 0;
        }
        int leftSum = diameterOfBinaryTreeHelper(node->left, maxi);
        int rightSum = diameterOfBinaryTreeHelper(node->right, maxi);
        maxi = max(maxi, leftSum + rightSum + 1);
        return max(leftSum, rightSum) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        diameterOfBinaryTreeHelper(root, maxi);
        return maxi - 1;
    }
};