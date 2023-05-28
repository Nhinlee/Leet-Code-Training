#include "../stdc++.h"

class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = num.length() - 1;
        while (num[i] == '0') {
            i--;
        }
        return num.substr(0, i + 1);
    }

    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rs = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<bool> tl(51), br(51);
                int c1 = 0, c2 = 0;

                int l = i - 1, k = j - 1;
                while (l >= 0 && l < n && k >= 0 && k < m) {
                    if (!tl[grid[l][k]]) {
                        tl[grid[l][k]] = true;
                        c1++;
                    }
                    l--;
                    k--;
                }

                l = i + 1, k = j + 1;
                while (l >= 0 && l < n && k >= 0 && k < m) {
                    if (!br[grid[l][k]]) {
                        br[grid[l][k]] = true;
                        c2++;
                    }
                    l++;
                    k++;
                }

                rs[i][j] = abs(c1 - c2);
            }
        }

        return rs;
    }

    long long minimumCost(string s) {
        int n = s.length();
        if (n == 1) return 0;

        return min(count(s, n, 0), count(s, n, 1));
    }

    long long count(string s, int n, int flipTo) {
        int mid = n / 2;
        int i = mid - 1, j = mid, flipCount = 0;
        long long cost = 0;
        while (i >= flipTo && s[i] == flipTo) i--;
        while (j < n && s[j] == flipTo) i--;
        for (; i >= 0; i--) {
            if ((flipCount + s[i] - '0') % 2 != flipTo) {
                cost += i + 1;
                flipCount++;
            }
        }

        flipCount = 0;
        for (; j < n; j++) {
            if ((flipCount + s[j] - '0') % 2 != flipTo) {
                cost += n - j;
                flipCount++;
            }
        }

        return cost;
    }

    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));

        int maxVisited = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && mat[i][j] > mat[i-1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                }
                if (j > 0 && mat[i][j] > mat[i][j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                }
                maxVisited = max(maxVisited, dp[i][j]);
            }
        }

        return maxVisited;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->minimumCost("00");
}