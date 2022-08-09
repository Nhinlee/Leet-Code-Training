#include "../stdc++.h"

class Solution {
private:
    int module = 1000000007;
public:
    // C1: Recursive
    int findPaths(int m, int n, int maxMove, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;

        maxMove--;
        if (maxMove < 0) return 0;

        int paths = 0;
        if (canMove(m, n, maxMove, i - 1, j)) paths += findPaths(m, n, maxMove, i - 1, j);
        if (canMove(m, n, maxMove, i + 1, j)) paths += findPaths(m, n, maxMove, i + 1, j);
        if (canMove(m, n, maxMove, i, j - 1)) paths += findPaths(m, n, maxMove, i, j - 1);
        if (canMove(m, n, maxMove, i, j + 1)) paths += findPaths(m, n, maxMove, i, j + 1);

        return paths;
    }

    bool canMove(int m, int n, int maxMove, int i, int j) {
        return i - maxMove < 0 || i + maxMove >= m || j - maxMove < 0 || j + maxMove >= n;
    }

    // C2: DP
    int findPathsC2(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;

        // Base Answer Table
        vector<vector<long long>> ans(m + 2), previousAns(m + 2);
        for (int i = 0; i < m + 2; i++) {
            ans[i] = vector<long long>(n + 2);
            previousAns[i] = vector<long long>(n + 2);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                previousAns[i][j] = extraPaths(i, j, m, n);
                ans[i][j] = extraPaths(i, j, m, n);
            }
        }

        // Bottom Up
        while (--maxMove) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    ans[i][j] = (previousAns[i - 1][j] + previousAns[i][j - 1] + previousAns[i + 1][j] +
                                 previousAns[i][j + 1]) % module;
                    ans[i][j] += extraPaths(i, j, m, n);
                }
            }

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    previousAns[i][j] = ans[i][j];
                }
            }
        }

        return ans[startRow + 1][startColumn + 1];
    }

    // Calculate extra path if current position at bound
    int extraPaths(int i, int j, int m, int n) {
        int paths = 0;
        if (m == 1 && n == 1) return 4;
        if (m == 1 || n == 1) paths++;
        if (isSpecialBound(i, j, m, n)) return paths + 2;
        if (isOnBound(i, j, m, n)) return paths + 1;
        return paths;
    }

    bool isOnBound(int i, int j, int m, int n) {
        return i == 1 || j == 1 || i == m || j == n;
    }

    bool isSpecialBound(int i, int j, int m, int n) {
        return i == 1 && j == 1
               || i == 1 && j == n
               || i == m && j == 1
               || i == m && j == n;
    }
};