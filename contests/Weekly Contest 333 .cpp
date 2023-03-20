#include "../stdc++.h"

class Solution {
public:
    // https://leetcode.com/contest/weekly-contest-333/problems/merge-two-2d-arrays-by-summing-values/
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
        map<int, int> flags;
        for (auto n: nums1) {
            flags[n[0]] += n[1];
        }

        for (auto n: nums2) {
            flags[n[0]] += n[1];
        }

        vector<vector<int>> rs;
        for (auto it: flags) {
            rs.push_back({it.first, it.second});
        }

        return rs;
    }

    // https://leetcode.com/contest/weekly-contest-333/problems/minimum-operations-to-reduce-an-integer-to-0/
    int minOperations(int n) {
        int k = 0;
        while (n > 0) {
            int i = getPower(n);
            int l = pow(2, i);
            int r = pow(2, i + 1);
            n = min(abs(n - l), abs(n - r));
            k++;
        }

        return k;
    }

    int getPower(int n) {
        int i = 0;
        while (pow(2, i) <= n) {
            i++;
        }

        return i - 1;
    }

    // https://leetcode.com/contest/weekly-contest-333/problems/count-the-number-of-square-free-subsets/
    //[11,2,19,7,9,27]
    //[26,6,4,27,6,18]
    //[9,13,19,23,7,27]
    const int module = 1e9 + 7;

    // WRONG: TODO: improve this
    int squareFreeSubsets(vector<int> &nums) {
        if (nums.size() == 1 && nums[0] == 1) return 1;

        set<int> primes = {2, 3, 5, 7, 11, 17, 19, 21, 23, 26, 27, 29,};

        int count = 0;
        for (auto x: nums) {
            if (primes.count(x) > 0) count++;
        }

        int rs = 0;
        for (int i = 1; i <= count; i++) {
            rs += C(i, count) % module;
        }

        return rs;
    }

    int C(int k, int n) {
        if (k == 0 || k == n) return 1;
        if (k == 1) return n;
        return C(k - 1, n - 1) + C(k, n - 1);
    }
};