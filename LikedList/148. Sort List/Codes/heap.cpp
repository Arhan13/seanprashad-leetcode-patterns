#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        while (head != nullptr)
        {
            int val = head->val;
            minH.push(val);
            head = head->next;
        }
        ListNode *newNode = new ListNode(0);
        ListNode *dummy = newNode;
        while (minH.size() > 0)
        {
            newNode->next = new ListNode(minH.top());
            newNode = newNode->next;
            minH.pop();
        }
        newNode->next = nullptr;
        return dummy->next;
    }
};