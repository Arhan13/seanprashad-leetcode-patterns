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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev == nullptr)
        {
            head = head->next;
        }
        else
        {
            prev->next = slow->next;
        }
        delete slow;
        return head;
    }
};