class Solution {
public:
/*
The time complexity of the isIdentical function is O(n), where n is the number of nodes in the larger tree. The function compares each node of the two trees once, so the time complexity is proportional to the number of nodes.
The time complexity of the isSubtree function depends on the number of nodes in the root tree and the subRoot tree. Let's denote m as the number of nodes in the root tree and k as the number of nodes in the subRoot tree.
In the worst case scenario, where the subRoot tree is not a subtree of the root tree, the isSubtree function will recursively traverse all nodes in the root tree and check if each subtree is identical to the subRoot tree. Therefore, the time complexity is O(m * k) in the worst case.

The space complexity of both functions is O(h), where h is the height of the tree. This is because the space used by the recursive call stack is proportional to the height of the tree. In the worst case, where the tree is skewed, the space complexity can be O(n), where n is the number of nodes in the tree.
*/
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1){
            return false;
        }
        if(!root2){
            return false;
        }
        return root1->val == root2->val && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root){
            return false;
        }
        if(isIdentical(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};