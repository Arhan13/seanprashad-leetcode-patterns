#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    int helper(Node *node, int maxHeight)
    {
        if (!node)
        {
            return 0;
        }
        int currentMaxHeight = 0;
        for (auto child : node->children)
        {
            currentMaxHeight = max(currentMaxHeight, helper(child, currentMaxHeight));
        }
        return maxHeight = max(maxHeight, 1 + currentMaxHeight);
    }

public:
    int maxDepth(Node *root)
    {
        int maxHeight = 0;
        return helper(root, maxHeight);
    }
};