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
    void dfs(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &minH)
    {
        if (!root)
        {
            return;
        }
        int val = root->val;
        minH.push(val);
        dfs(root->left, minH);
        dfs(root->right, minH);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        dfs(root, minH);
        if (k > 0)
        {
            k--;
        }
        while (k--)
        {
            minH.pop();
        }
        return minH.top();
    }
};