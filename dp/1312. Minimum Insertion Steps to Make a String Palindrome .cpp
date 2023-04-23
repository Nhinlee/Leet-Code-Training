#include "../stdc++.h"

class Solution {
public:

    // DP with top-down solution
    int minInsertions(string s) {
        map<pair < int, int>, int > memo;
        return s.size() - dp(s, 0, s.size() - 1, memo);
    }

    int dp(string s, int i, int j, map<pair < int, int>, int> &memo) {
        if (j < 0 || i >= s.size()) return 0;
        if (i == j) return 1;
        if (i > j) return 0;

        if (memo[{i, j}] > 0) {
            return memo[{i, j}];
        }

        if (s[i] == s[j]) {
            memo[{i, j}] = dp(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[{i, j}] = max(dp(s, i + 1, j, memo), dp(s, i, j - 1, memo));
        }


        return memo[{i, j}];
    }

    // DP with bottom-up solution
    int minInsertionsC2(string s) {
        int n = s.length();
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j], dp[j-1]) + 1;
                }
                prev = temp;
            }
        }
        return dp[n-1];
    }
};