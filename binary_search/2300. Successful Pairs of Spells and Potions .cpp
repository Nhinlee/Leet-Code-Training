#include "../stdc++.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        vector<int> rs;
        int n = potions.size() - 1;
        sort(potions.begin(), potions.end());

        for (auto s: spells) {
            int i = binarySearchPos(potions, s, success);
            rs.push_back(n - i + 1);
        }

        return rs;
    }

    int binarySearchPos(vector<int> &potions, int x, long long success) {
        int l = 0, r = potions.size() - 1, mid;
        long long mult;
        while (l <= r) {
            mid = (l + r) / 2;
            mult = potions[mid];
            mult *= x;
            if (mult >= success) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};