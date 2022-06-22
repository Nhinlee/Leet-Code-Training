#include "../stdc++.h"

class Solution {
public:
    int pairSum(ListNode *head) {
        vector<int> values;
        ListNode *p = head;
        while (p != NULL) {
            values.push_back(p->val);
            p = p->next;
        }

        int i = 0, j = values.size() - 1, maxx = 0;
        while (i < j) {
            maxx = max(maxx, values[i] + values[j]);
            i++;
            j--;
        }

        return maxx;
    }

    int pairSumC2(ListNode *head) {
        ListNode *slow = head, *fast = head;

        // Get mid of the list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse a haft of the list
        ListNode *nextNode, *prev = NULL;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Maximum of the twin
        int maxx = 0;
        while (prev) {
            maxx = max(maxx, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return maxx;
    }
};
//
//
//int main() {
//    Solution *s = new Solution();
//    ListNode a1(5);
//    ListNode a2(4);
//    ListNode a3(2);
//    ListNode a4(1);
//    a1.next = &a2;
//    a2.next = &a3;
//    a3.next = &a4;
//
//    int rs = s->pairSumC2(&a1);
//    cout << rs;
//}
