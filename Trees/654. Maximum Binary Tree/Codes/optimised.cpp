#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

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
    TreeNode *constructMaximumBinaryTreeHelper(vector<int> &nums, int startIndex, int endIndex)
    {
        if (startIndex > endIndex)
        {
            return nullptr;
        }
        int maxIndex = startIndex;
        for (int i = startIndex + 1; i <= endIndex; i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        TreeNode *newNode = new TreeNode(nums[maxIndex]);
        newNode->left = constructMaximumBinaryTreeHelper(nums, startIndex, maxIndex - 1);
        newNode->right = constructMaximumBinaryTreeHelper(nums, maxIndex + 1, endIndex);
        return newNode;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
    }
};