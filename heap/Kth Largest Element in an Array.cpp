#include "../stdc++.h"

// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    // C1: Max Heap
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> maxHeap;
        int rs;

        for (auto x: nums) {
            maxHeap.push(x);
        }

        while (!maxHeap.empty() && k-- > 0) {
            rs = maxHeap.top();
            maxHeap.pop();
        }

        return rs;
    }

    // C2: smarter & faster a little bit @@ - Min Heap
    int findKthLargestC2(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto x: nums) {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};