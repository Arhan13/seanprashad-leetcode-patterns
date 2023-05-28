#include <bits/stdc++.h>
using namespace std;

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
    int pathSumFrom(TreeNode *root, long long int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        int count = 0;
        if (root->val == targetSum)
        {
            count++;
        }
        count += pathSumFrom(root->left, targetSum - root->val);
        count += pathSumFrom(root->right, targetSum - root->val);
        return count;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        int count = 0;
        count += pathSumFrom(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};