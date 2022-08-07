#include "../stdc++.h"

const int MOD = 1e9 + 7;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(5, 0));

        // Base row
        dp[0] = vector<long>(5, 1);

        // Bottom up
        for (int i = 0; i < n; i++) {

            // a
            dp[i + 1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % MOD;

            // e
            dp[i + 1][1] = (dp[i][0] + dp[i][2]) % MOD;

            // i
            dp[i + 1][2] = (dp[i][1] + dp[i][3]) % MOD;

            // o
            dp[i + 1][3] = (dp[i][2]) % MOD;

            // u
            dp[i + 1][4] = (dp[i][2] + dp[i][3]) % MOD;
        }

        // Result
        int rs = 0;
        for (int i = 0; i < 5; i++) {
            rs = (rs + dp[n - 1][i]) % MOD;
        }

        return rs;
    }
};