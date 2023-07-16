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
            return NULL;
        }
        Node *copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node *> q;
        q.push(node);
        while (q.size() > 0)
        {
            Node *currNode = q.front();
            q.pop();
            for (Node *neighbor : currNode->neighbors)
            {
                if (copies.find(neighbor) == copies.end())
                {
                    // If there is no copy of the node we will create one
                    copies[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                copies[currNode]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copies[node];
    }
};