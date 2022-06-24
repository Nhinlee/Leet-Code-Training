#include "../stdc++.h"

#define psi pair<int, int>

class MyComparator {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> tops;
        map<int, int> flags;
        priority_queue<psi, vector<psi >, MyComparator> maxHeap;

        for (auto x: nums) {
            flags[x]++;
        }

        for (auto it = flags.begin(); it != flags.end(); it++) {
            maxHeap.push(pair<int, int>{it->first, it->second});
        }

        while (k--) {
            tops.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return tops;
    }
};