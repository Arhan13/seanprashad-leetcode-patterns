#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (ListNode *list : lists)
        {
            while (list && list->next)
            {
                ListNode *currNode = list;
                minH.push(currNode->val);
                list = list->next;
            }
            if (list)
            {
                minH.push(list->val);
            }
        }
        ListNode *ans = new ListNode();
        ListNode *dummy = ans;
        while (minH.size() > 0)
        {
            int topNodeVal = minH.top();
            minH.pop();
            ans->next = new ListNode(topNodeVal);
            ans = ans->next;
        }
        return dummy->next;
    }
};