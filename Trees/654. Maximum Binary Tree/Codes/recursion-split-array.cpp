#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
// One line inutition: The root is the maximum number in the array, and the left subtree and right subtree are the maximum binary trees of the left and right subarrays of the maximum number.
// So we split the array into two parts, and recursively construct the left and right subtrees.
// First part is from 0 to maxIndex-1, second part is from maxIndex+1 to nums.size()-1
// We can use getMaxIndex function to get the index of the maximum number in the array.

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
    int getMaxIndex(vector<int> &nums)
    {
        auto maxIt = max_element(nums.begin(), nums.end());
        int maxIndex = distance(nums.begin(), maxIt);
        return maxIndex;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        int maxIndex = getMaxIndex(nums);
        vector<int> _leftArray = {};
        vector<int> _rightArray = {};
        for (int i = 0; i < maxIndex; i++)
        {
            _leftArray.push_back(nums[i]);
        }
        for (int j = maxIndex + 1; j < nums.size(); j++)
        {
            _rightArray.push_back(nums[j]);
        }
        TreeNode *newNode = new TreeNode(nums[maxIndex]);
        newNode->left = constructMaximumBinaryTree(_leftArray);
        newNode->right = constructMaximumBinaryTree(_rightArray);
        return newNode;
    }
};