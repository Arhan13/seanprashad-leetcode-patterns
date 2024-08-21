#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> visitedMap;

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return NULL;
        }
        if (visitedMap.find(head) != visitedMap.end())
        {
            return visitedMap[head];
        }
        Node *node = new Node(head->val, NULL, NULL);
        visitedMap[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};