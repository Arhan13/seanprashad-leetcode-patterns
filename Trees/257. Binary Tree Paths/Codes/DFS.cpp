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

// Time Complexity - O(N)
// Space Complexity - O(N)
/*
-------------------------Explanation--------------------------------
The time complexity of the binaryTreePaths function is O(n),
where n is the number of nodes in the binary tree.
This is because the function visits each node exactly once during the DFS traversal.

The space complexity of the binaryTreePaths function is also O(n),
where n is the number of nodes in the binary tree.
This is because the function uses two vectors to store the paths: ans to store the answer paths and path to store the current path.
The maximum size of the path vector is the height of the binary tree, which is O(log n) for a balanced binary tree and O(n) for a skewed binary tree.
Therefore, the overall space complexity is O(n) for both balanced and skewed binary trees.
--------------------------------------------------------------------
*/
//----Intuition behind the solution-----------------------------------
// This code implements a function that takes a binary tree as input
// and returns a vector of strings representing all the root-to-leaf
// paths in the tree using a depth-first search (DFS) algorithm.
// The time complexity of the function is O(n), where n is the number of nodes in the binary tree, and the space complexity is also O(n).
//------------------------Solution------------------------------------
class Solution
{
public:
    void DFS(TreeNode *root, vector<string> &ans, vector<string> &path)
    {
        // Base case: if the current node is null, return
        if (!root)
        {
            return;
        }
        // If the current node is a leaf node, add the node's value to the current path
        // and convert the path to a string, then add the string to the answer vector
        if (!root->left && !root->right)
        {
            path.push_back(to_string(root->val)); // add the node's value to the current path
            string path_to_return = "";
            for (int i = 0; i < path.size(); i++)
            {
                if (i == path.size() - 1)
                {
                    path_to_return += path[i]; // add the last node's value to the path string
                }
                else
                {
                    path_to_return += path[i] + "->"; // add the node's value and "->" to the path string
                }
            }
            ans.push_back(path_to_return); // add the path string to the answer vector
            path.pop_back();               // remove the node's value from the current path
            return;
        }
        // If the current node is not a leaf node, visit all its children
        if (root->left)
        {
            path.push_back(to_string(root->val)); // add the node's value to the current path
            DFS(root->left, ans, path);           // visit the left child
            path.pop_back();                      // remove the node's value from the current path
        }
        if (root->right)
        {
            path.push_back(to_string(root->val)); // add the node's value to the current path
            DFS(root->right, ans, path);          // visit the right child
            path.pop_back();                      // remove the node's value from the current path
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        vector<string> path = {};
        DFS(root, ans, path);
        return ans;
    }
};