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
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *dummy = head;
        while (dummy)
        {
            st.push(dummy->val);
            dummy = dummy->next;
        }
        while (head)
        {
            int ele = st.top();
            st.pop();
            if (head->val != ele)
            {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};