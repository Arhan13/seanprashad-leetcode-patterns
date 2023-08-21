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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        // We will make two lists odd and even
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;

        while (odd->next && even->next)
        {
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};