#include "../stdc++.h"

class Solution {
public:
    vector<int> memos = vector<int>(366);
    set<int> daySet;
    vector<int> costs;

    int mincostTickets(vector<int> &days, vector<int> &c) {
        costs = vector<int>(c);

        for (auto d: days) {
            daySet.insert(d);
        }

        return dp(1);
    }

    int dp(int i) {
        if (i > 365) return 0;
        if (memos[i] != 0) return memos[i];

        int ans = 0;
        if (daySet.count(i)) {
            ans = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
        } else {
            ans = dp(i+1);
        }

        memos[i] = ans;
        return ans;
    }
};