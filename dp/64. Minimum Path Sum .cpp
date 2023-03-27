#include "../stdc++.h"

class Solution {
public:
    // DFS - recursive - TLE
    int minPathSum(vector<vector<int>> &grid) {
        int sum = 0, minSum = INT_MAX;

        dfs(grid, 0, 0, sum, minSum);

        return minSum;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &currSum, int &minSum) {
        int n = grid.size(), m = grid[0].size();
        if (i >= n || j >= m) return;

        currSum += grid[i][j];
        if (i == n - 1 && j == m - 1) {
            minSum = min(minSum, currSum);
        }

        dfs(grid, i + 1, j, currSum, minSum);
        dfs(grid, i, j + 1, currSum, minSum);

        currSum -= grid[i][j];
    }

    // DP - Time: O(n*m), Space: O(n)
    int minPathSumC2(vector<vector<int>> &grid) {
        vector<int> memos(grid[0]);

        for (int i = 1; i < memos.size(); i++) {
            memos[i] += memos[i - 1];
        }

        int i = 1, n = grid.size(), m = grid[0].size();
        while (i < n) {
            memos[0] += grid[i][0];

            for (int j = 1; j < m; j++) {
                memos[j] = min(memos[j] + grid[i][j], memos[j - 1] + grid[i][j]);
            }
            i++;
        }

        return memos[m - 1];
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> a = {{1, 3, 1},
                             {1, 5, 1},
                             {4, 2, 1}};
    s->minPathSumC2(a);
}