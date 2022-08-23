#include "../stdc++.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        // Get size of linked list
        int n = 0;
        ListNode *p = head, *pre = nullptr, *next = nullptr;
        while (p != nullptr) {
            n++;
            p = p->next;
        }

        // Change direction
        int i = 0;
        p = head;
        while (i < n / 2) {
            i++;
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        // Check palindrome
        if (n % 2 != 0 && next != nullptr) {
            next = next->next;
        }

        while (pre != nullptr && next != nullptr) {
            if (pre->val != next->val) return false;
            pre = pre->next;
            next = next->next;
        }

        return true;
    }
};