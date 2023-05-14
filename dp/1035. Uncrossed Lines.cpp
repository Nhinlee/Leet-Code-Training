#include "../stdc++.h"

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        map<pair<int, int>, int> memo;
        return dp(nums1, nums2, 0, 0, memo);
    }

    // Memo + Recursive - Top down
    int dp(vector<int> &nums1, vector<int> &nums2, int i, int j, map<pair<int, int>, int> &memo) {
        int n1 = nums1.size(), n2 = nums2.size();
        int rs = 0;

        if (i >= n1 || j >= n2) {
            return 0;
        }

        if (memo[{i, j}]) return memo[{i, j}];

        if (nums1[i] == nums2[j]) {
            rs = 1 + dp(nums1, nums2, i + 1, j + 1, memo);
        } else {
            rs = max(dp(nums1, nums2, i + 1, j, memo), dp(nums1, nums2, i, j + 1, memo));
        }

        memo[{i, j}] = rs;
        return rs;
    }

    // Bottom Up
    int maxUncrossedLinesC2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};