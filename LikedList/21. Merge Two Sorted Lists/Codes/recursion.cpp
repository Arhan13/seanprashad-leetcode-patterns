#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == 0)
        {
            return l2;
        }
        if (l2 == 0)
        {
            return l1;
        }
        ListNode *c;
        if ((l1->val) > (l2->val))
        {
            c = l2;
            c->next = mergeTwoLists(l2->next, l1);
        }
        else
        {
            c = l1;
            c->next = mergeTwoLists(l1->next, l2);
        }
        return c;
    }
};