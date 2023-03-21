#include "../stdc++.h"

class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long rs = 0, count0 = 0;
        for (auto x: nums) {
            count0 = x == 0 ? count0 + 1 : 0;
            rs += count0;
        }

        return rs;
    }
};