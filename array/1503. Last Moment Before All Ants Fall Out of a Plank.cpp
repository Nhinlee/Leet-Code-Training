#include "../stdc++.h"

class Solution {
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int ans = 0;
        for (auto &pos: left) {
            ans = max(ans, pos);
        }

        for (auto &pos: right) {
            ans = max(ans, n - pos);
        }

        return ans;
    }
};