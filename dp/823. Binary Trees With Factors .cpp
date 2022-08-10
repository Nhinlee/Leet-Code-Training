#include "../stdc++.h"

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        // sort
        sort(arr.begin(), arr.end());

        // save all element in map index
        int n = arr.size();
        map<int, int> indexes;
        for (int i = 0; i < n; i++) {
            indexes[arr[i]] = i;
        }

        // dp
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (indexes.count(right) > 0) {
                        dp[i] = (dp[i] + dp[j] * dp[indexes[right]]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (auto x: dp) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};