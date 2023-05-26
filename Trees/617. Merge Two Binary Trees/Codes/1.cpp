#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /*
    The time complexity of the mergeTrees function depends on the number of nodes in the two trees being merged. Let's denote m as the number of nodes in root1 and n as the number of nodes in root2.
    In the worst case scenario, where both trees have m and n nodes respectively and there is no overlap between the nodes, the function needs to create a new node for each pair of corresponding nodes. Therefore, the time complexity is O(min(m, n)), as the function only needs to process up to the minimum number of nodes between the two trees.

    The space complexity of the mergeTrees function is also dependent on the number of nodes in the resulting merged tree. In the worst case, where both trees have m and n nodes respectively and there is no overlap between the nodes, the resulting merged tree would have m + n nodes. Therefore, the space complexity is O(m + n) in this case.
    Note that if there is overlap between the nodes, the actual time and space complexity can be lower, as the function can reuse the existing nodes instead of creating new ones.
    */
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }
        if (!root1)
        {
            return root2;
        }
        if (!root2)
        {
            return root1;
        }
        TreeNode *newNode = new TreeNode(root1->val + root2->val);
        newNode->left = mergeTrees(root1->left, root2->left);
        newNode->right = mergeTrees(root1->right, root2->right);
        return newNode;
    }
    void inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    TreeNode *mergedTree = s.mergeTrees(root1, root2);
    // print the merged tree using inorder traversal
    cout << "Inorder traversal of the merged tree: ";
    s.inorderTraversal(mergedTree);
    cout << endl;
    return 0;
}
