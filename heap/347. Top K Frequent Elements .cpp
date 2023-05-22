#include "../stdc++.h"

typedef pair<int,int> pp;

class Solution {
public:
    static bool compare(pp a, pp b) {
        return a.second < b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> flags;
        priority_queue<pp, vector<pp>, function<bool(pp,pp)>> pq(compare);
        vector<int> rs;

        for(auto x : nums) {
            flags[x]++;
        }

        for (auto it: flags) {
            pq.push({it.first, it.second});
        }

        while(k--) {
            rs.push_back(pq.top().first);
            pq.pop();
        }

        return rs;
    }
};

