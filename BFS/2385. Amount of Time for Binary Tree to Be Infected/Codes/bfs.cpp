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
    void dfs(unordered_map<int, vector<int>> &g, TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        if (node->left)
        {
            g[node->val].push_back(node->left->val);
            g[node->left->val].push_back(node->val);
            dfs(g, node->left);
        }
        if (node->right)
        {
            g[node->val].push_back(node->right->val);
            g[node->right->val].push_back(node->val);
            dfs(g, node->right);
        }
        return;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> g;
        dfs(g, root);

        int maxDistance = 0;
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        q.push({0, start});
        seen.insert(start);
        while (q.size() > 0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // interate over the neighbours of y
            for (int neighbour : g[y])
            {
                // If the neighbour is not seen
                if (seen.find(neighbour) == seen.end())
                {
                    // Add it to the queue
                    q.push({x + 1, neighbour});
                    seen.insert(neighbour);
                    maxDistance = max(x + 1, maxDistance);
                }
            }
        }
        return maxDistance;
    }
};