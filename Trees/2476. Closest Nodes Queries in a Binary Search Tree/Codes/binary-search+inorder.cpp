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

/*
The time complexity of the closestNodes function is O(n log n + q log n), where n is the number of nodes in the tree and q is the number of queries. This is because we first perform an inorder traversal of the tree to create the inorder vector, which takes O(n) time. Then, for each query, we perform a binary search on the inorder vector, which takes O(log n) time. Therefore, the total time complexity is O(n log n + q log n).
The space complexity of the closestNodes function is O(n + q), where n is the number of nodes in the tree and q is the number of queries. This is because we create a vector<int> to store the inorder traversal of the tree, which takes O(n) space. We also create a vector<vector<int>> to store the answer for each query, which takes O(q) space. Therefore, the total space complexity is O(n + q).
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
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<int> inorder;
        vector<vector<int>> answer(queries.size(), vector<int>(2, -1));
        inorderTraversal(root, inorder);
        for (int i = 0; i < queries.size(); i++)
        {
            int min = -1;
            int max = -1;
            int left = 0;
            int right = inorder.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (inorder[mid] == queries[i])
                {
                    answer[i][0] = inorder[mid];
                    answer[i][1] = inorder[mid];
                    break;
                }
                else if (inorder[mid] < queries[i])
                {
                    min = inorder[mid];
                    left = mid + 1;
                }
                else
                {
                    max = inorder[mid];
                    right = mid - 1;
                }
            }
            if (answer[i][0] == -1 && min != -1)
            {
                answer[i][0] = min;
            }
            if (answer[i][1] == -1 && max != -1)
            {
                answer[i][1] = max;
            }
        }
        return answer;
    }
};