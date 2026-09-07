/*
Pattern: Linked List
Mistake: I jumped quickly
Key idea: Keep window valid by removing duplicates.
Time: O(n)
*/


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
#include "libs.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }


    // just in case, recursive version
    ListNode* reverseListRecur(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseListRecur(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};






