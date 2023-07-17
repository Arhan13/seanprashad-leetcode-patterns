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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (auto list : lists)
        {
            while (list && list->next)
            {
                minH.push(list->val);
                list = list->next;
            }
            if (list)
            {
                minH.push(list->val);
            }
        }
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (minH.size() > 0)
        {
            int top = minH.top();
            minH.pop();
            curr->next = new ListNode();
            curr->next->val = top;
            curr = curr->next;
        }
        return dummy->next;
    }
};