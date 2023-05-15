#include "../stdc++.h"

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
class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *left = head, *right = head;
        for (int i = 0; i < k-1; i++) {
            right = right->next;
        }

        ListNode *end = right;
        while (right->next) {
            right = right->next;
            left = left->next;
        }

        swap(left->val, end->val);

        return head;
    }
};