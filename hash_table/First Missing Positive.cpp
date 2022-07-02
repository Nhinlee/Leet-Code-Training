#include "../stdc++.h"

// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        map<int, int> flags;
        int minn = 1;

        for (auto x: nums) {
            flags[x]++;
        }

        while (flags[minn] > 0) {
            minn++;
        }

        return minn;
    }

    int firstMissingPositiveC2(vector<int> &nums) {
        vector<bool> flags(nums.size() + 1);
        int n = flags.size();

        for (auto x: nums) {
            if (x > 0 && x < n) flags[x] = true;
        }

        for (int i = 1; i < n; i++) {
            if (!flags[i]) return i;
        }

        return n;
    }


    int firstMissingPositiveC3(vector<int> &a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            while (a[i] > 0 && a[i] < n && a[a[i] - 1] != a[i]) {
                swap(a[i], a[a[i] - 1]);

            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != i+1) return i + 1;
        }

        return n + 1;
    }
};