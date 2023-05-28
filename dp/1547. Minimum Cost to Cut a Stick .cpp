#include "../stdc++.h"

class Solution {
public:
    int minCost(int n, vector<int> &cuts) {
        int length = cuts.size();
        std::sort(cuts.begin(), cuts.end());
        return cut(cuts, 0, length, n);
    }

    int cut(vector<int> &cuts, int i, int j, int n) {
        if (i == j) return n;

        int rs = INT_MAX;
        for (int pos = i; pos < j; pos++) {
            rs = min(rs, n + cut(cuts, i, pos, pos) + cut(cuts, pos, j, j));
        }

        return rs;
    }
};