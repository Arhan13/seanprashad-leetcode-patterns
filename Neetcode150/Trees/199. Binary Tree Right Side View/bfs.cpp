#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

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
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vi ans = {};
        if (!root)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        ans.push_back(root->val);
        vi currPath = {};
        while (q.size())
        {
            int levelSize = q.size();
            currPath = {};
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();
                if (currNode->left)
                {
                    q.push(currNode->left);
                    currPath.push_back(currNode->left->val);
                }
                if (currNode->right)
                {
                    q.push(currNode->right);
                    currPath.push_back(currNode->right->val);
                }
            }
            int currPathSize = currPath.size();
            if (currPathSize > 0)
            {
                ans.push_back(currPath[currPathSize - 1]);
            }
        }
        return ans;
    }
};