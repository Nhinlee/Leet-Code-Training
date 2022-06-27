#include "../stdc++.h"

// https://leetcode.com/problems/finding-the-users-active-minutes/
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        map<int, set<int>> flags;
        vector<int> ans(k);

        for (auto log: logs) {
            flags[log[0]].insert(log[1]);
        }

        for (auto f: flags) {
            ans[f.second.size() - 1]++;
        }

        return ans;
    }
};
