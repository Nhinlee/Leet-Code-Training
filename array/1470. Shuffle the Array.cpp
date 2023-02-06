#include "../stdc++.h"

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> rs;
        for (int i = 0; i < n; i++) {
            rs.push_back(nums[i]);
            rs.push_back(nums[i + n]);
        }

        return rs;
    }
};