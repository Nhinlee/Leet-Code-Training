#include "../stdc++.h"

class Solution {
public:
    // Normal Recursive
    int combinationSum4C1(vector<int> &nums, int target) {
        if (target == 0) return 1;

        int rs = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                rs += combinationSum4C1(nums, target - nums[i]);
            }
        }

        return rs;
    }

    // DP: Top-down
    vector<int> targetMemo;

    int combinationSum4(vector<int> &nums, int target) {
        targetMemo = vector<int>(target + 1, -1);

        return combination(nums, target);
    }

    int combination(vector<int> &nums, int target) {
        if (targetMemo[target] != -1) return targetMemo[target];
        if (target == 0) return 1;

        int rs = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                rs += combination(nums, target - nums[i]);
            }
        }

        return rs;
    }

    // DP: Bottom-up
    int combinationSum4V2(vector<int> &nums, int target) {
        vector<int> targetMemo = vector<int>(target + 1, 0);
        targetMemo[0] = 1;

        for (int i = 1; i < targetMemo.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    targetMemo[i] += targetMemo[i - nums[j]];
                }
            }
        }

        return targetMemo[target];
    }
};