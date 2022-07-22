#include "../stdc++.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto *headLess = new ListNode(-1);
        auto *headGrater = new ListNode(-1);
        ListNode *pL = headLess, *pG = headGrater, *p = head;

        while (p != nullptr) {
            if (p->val >= x) {
                pG->next = p;
                pG = p;
            } else {
                pL->next = p;
                pL = p;
            }
            p = p->next;
        }

        pL->next = headGrater->next;
        pG->next = nullptr;
        return headLess->next;
    }
};

int main() {
    // Solution
    Solution *s = new Solution();

    // DATA
    vector<ListNode *> l{
            new ListNode(1),
            new ListNode(4),
            new ListNode(3),
            new ListNode(2),
            new ListNode(5),
            new ListNode(2),
    };
    for (int i = 0; i < l.size() - 1; i++) {
        l[i]->next = l[i + 1];
    }

    s->partition(l[0], 3);
    return 0;
}