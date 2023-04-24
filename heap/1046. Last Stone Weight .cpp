#include "../stdc++.h"

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for (auto st: stones) {
            maxHeap.push(st);
        }

        while (maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if (a != b) maxHeap.push(abs(a - b));
        }

        if (!maxHeap.empty()) return maxHeap.top();

        return 0;
    }
};