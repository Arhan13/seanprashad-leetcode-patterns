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
};