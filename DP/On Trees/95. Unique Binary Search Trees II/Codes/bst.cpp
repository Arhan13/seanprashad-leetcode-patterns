#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    vector<TreeNode *> generateTreesInRange(int left, int right)
    {
        vector<TreeNode *> trees;
        if (left > right)
        {
            trees.push_back(nullptr);
        }
        else
        {
            for (int rootValue = left; rootValue <= right; rootValue++)
            {
                vector<TreeNode *> leftTreeNodes = generateTreesInRange(left, rootValue - 1);
                vector<TreeNode *> rightTreeNodes = generateTreesInRange(rootValue + 1, right);

                for (TreeNode *leftTreeNode : leftTreeNodes)
                {
                    for (TreeNode *rightTreeNode : rightTreeNodes)
                    {
                        TreeNode *root = new TreeNode(rootValue, leftTreeNode, rightTreeNode);
                        trees.push_back(root);
                    }
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return generateTreesInRange(1, n);
    }
};