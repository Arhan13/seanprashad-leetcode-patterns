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
    int maxPathSumHelper(TreeNode *node, int &maxi, unordered_map<TreeNode *, int> &ump)
    {
        if (!node)
        {
            return 0;
        }
        if (ump.count(node))
        {
            return ump[node];
        }
        int leftSum = max(0, maxPathSumHelper(node->left, maxi, ump));
        int rightSum = max(0, maxPathSumHelper(node->right, maxi, ump));
        maxi = max(maxi, leftSum + rightSum + node->val);
        /*
            The path sum gain contributed by the subtree can be derived from a path that includes at most one child of the root. You may wonder, why can't we include both children? If we include both children in the path, the path would have to make a fork at the root. The root is already connected to its parent. Now, if we include both children as well, with three connections, it wouldn't be a valid path anymore. Therefore, we can say that the path would consist of at most one child of the root.
        */
        ump[node] = max(leftSum, rightSum) + node->val;
        return ump[node];
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        unordered_map<TreeNode *, int> ump;
        maxPathSumHelper(root, maxi, ump);
        return maxi;
    }
};