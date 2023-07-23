#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (q.size() > 0)
        {
            int qSize = q.size();
            // Stores nodes at a particular level
            vector<Node *> _temp = {};
            while (qSize--)
            {
                Node *currNode = q.front();
                q.pop();
                _temp.push_back(currNode);
                if (currNode->left)
                {
                    q.push(currNode->left);
                }
                if (currNode->right)
                {
                    q.push(currNode->right);
                }
            }
            // Now we will create the right pointer in each node at that level
            for (int i = 0; i < _temp.size() - 1; i++)
            {
                _temp[i]->next = _temp[i + 1];
            }
        }
        return root;
    }
};