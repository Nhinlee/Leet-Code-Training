#include "../stdc++.h"

class Solution {
public:
    const int MOD = 1e9 + 7;

    int pow2(int x, int y) {
        int res = 1;
        while (y > 0) {
            if (y & 1) res = (1LL * res * x) % MOD;
            x = (1LL * x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1, res = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pow2(2, r - l)) % MOD;
                l++;
            }
        }
        return res;
    }
};