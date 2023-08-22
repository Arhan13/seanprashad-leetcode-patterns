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
    int dfs(TreeNode *node, bool canRob, unordered_map<TreeNode *, int> &robResults, unordered_map<TreeNode *, int> &doesNotRobResults)
    {
        if (!node)
        {
            return 0;
        }
        if (canRob)
        {
            // When the current node can be robbed
            auto it = robResults.find(node);
            if (it != robResults.end())
            {
                return robResults[node];
            }
            int rob = node->val + dfs(node->left, false, robResults, doesNotRobResults) + dfs(node->right, false, robResults, doesNotRobResults);
            int notRob = dfs(node->left, true, robResults, doesNotRobResults) + dfs(node->right, true, robResults, doesNotRobResults);
            int res = max(rob, notRob);
            robResults[node] = res;
            return robResults[node];
        }
        else
        {
            // When the current node cannot be robbed
            auto it = doesNotRobResults.find(node);
            if (it != doesNotRobResults.end())
            {
                return doesNotRobResults[node];
            }
            int notRob = dfs(node->left, true, robResults, doesNotRobResults) + dfs(node->right, true, robResults, doesNotRobResults);
            doesNotRobResults[node] = notRob;
            return doesNotRobResults[node];
        }
    }

public:
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> robResults;
        unordered_map<TreeNode *, int> notRobResults;
        return dfs(root, true, robResults, notRobResults);
    }
};