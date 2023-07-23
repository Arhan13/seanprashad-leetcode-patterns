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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (q.size() > 0)
        {
            int qSize = q.size();
            vector<int> _temp = {};
            while (qSize--)
            {
                TreeNode *currNode = q.front();
                q.pop();
                _temp.push_back(currNode->val);
                if (currNode->left)
                {
                    q.push(currNode->left);
                }
                if (currNode->right)
                {
                    q.push(currNode->right);
                }
            }
            ans.push_back(_temp);
        }
        return ans;
    }
};