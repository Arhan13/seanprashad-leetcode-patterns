#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> copies;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }
        if (copies.find(node) == copies.end())
        {
            // The node copy does not exist
            // So we will make a new copy
            copies[node] = new Node(node->val, {});
            // Now we need to complete the new cloned node
            for (auto neighbour : node->neighbors)
            {
                // We connect the cloned node with the cloned neigbours
                copies[node]->neighbors.push_back(cloneGraph(neighbour));
            }
        }
        return copies[node];
    }
};