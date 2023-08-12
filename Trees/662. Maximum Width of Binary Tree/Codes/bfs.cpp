#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        long long maxWidth = 1;
        queue<pair<TreeNode *, long long>> q;
        // If there is a node Ci
        // The left child node is at 2*Ci and the right child node will be at 2*Ci + 1
        // Let the index of the root be 0
        // Lets add the root node into the queue
        q.push(make_pair(root, 0));
        // Now we need to iterate throught the tree
        while (!q.empty())
        {
            // Grabbing the first element in the row
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            maxWidth = max(maxWidth, end - start + 1);
            // Variable for the last element in the queue
            pair<TreeNode *, long long> currElem;
            for (int i = 0; i < cnt; i++)
            {
                currElem = q.front();
                q.pop();
                TreeNode *currNode = currElem.first;
                long long currentIndex = currElem.second - start;
                if (currNode->left)
                {
                    q.push(make_pair(currNode->left, (long long)2 * currentIndex));
                }
                if (currNode->right)
                {
                    q.push(make_pair(currNode->right, (long long)2 * currentIndex + 1));
                }
            }
        }
        return maxWidth;
    }
};