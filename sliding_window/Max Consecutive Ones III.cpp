#include "../stdc++.h"

class Solution {
public:
    // C1
    int longestOnes(vector<int> &nums, int k) {
        int i = 0, j = 0, n = nums.size(), count = 0, rs = 0;

        //
        while (j < n) {
            if (nums[j] == 0) count++;
            if (count > k + 1) break;
            j++;
        }
        if (count <= k) return n;
        while (i < n && nums[i] != 0) i++;

        //
        while (i < n) {
            rs = max(rs, j - i - 1);

            i++;
            j++;
            while (i < n && nums[i] != 0) i++;
            while (j < n && nums[j] != 0) j++;
        }

        return rs;
    }

    // C2: primary way
    int longestOnesC2(vector<int>& A, int K) {
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) K--;
            if (K < 0 && A[i++] == 0) K++;
        }
        return j - i;
    }
};
