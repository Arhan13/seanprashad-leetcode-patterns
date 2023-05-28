#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void populateParentMap(TreeNode *currentNode, TreeNode *parentNode, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        // We take two main params, parentNode and currentNode
        // We don't need parents of NULL nodes
        if (!currentNode)
        {
            return;
        }
        // Creating the mapping btw child and parent
        parentMap[currentNode] = parentNode;
        // Recursively calling on the left and right child
        populateParentMap(currentNode->left, currentNode, parentMap);
        populateParentMap(currentNode->right, currentNode, parentMap);
        return;
    }
    void populate(TreeNode *currentNode, int k, unordered_map<TreeNode *, TreeNode *> parentMap, set<TreeNode *> &visited, vector<int> &ans)
    {
        // NULL nodes are not part of the tree
        // When k < 0, we exceed the distance k
        // All the nodes are unique, so we can save them in a set and save compute
        if (!currentNode || k < 0 || visited.find(currentNode) != visited.end())
        {
            return;
        }
        // Insert the node in the set
        visited.insert(currentNode);
        // These nodes are at a distance of k
        if (k == 0)
        {
            ans.push_back(currentNode->val);
        }
        // We need to check 3 directions
        // 1. Left
        populate(currentNode->left, k - 1, parentMap, visited, ans);
        // 2. Right
        populate(currentNode->right, k - 1, parentMap, visited, ans);
        // 3. Top
        populate(parentMap[currentNode], k - 1, parentMap, visited, ans);
        return;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        set<TreeNode *> visited;
        // Make a mapping of the parents, we need this because we might need to move in the upwards direction
        // If we only needed nodes at a distance K from the root, then we won't need the parentMap
        unordered_map<TreeNode *, TreeNode *> parentMap;
        populateParentMap(root, NULL, parentMap);
        populate(target, k, parentMap, visited, ans);
        return ans;
    }
};