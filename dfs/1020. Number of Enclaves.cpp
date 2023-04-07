#include "../stdc++.h"

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int &count) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = 0;
        count++;

        dfs(i + 1, j, grid, count);
        dfs(i - 1, j, grid, count);
        dfs(i, j + 1, grid, count);
        dfs(i, j - 1, grid, count);
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int cellCount = 0;
        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid, cellCount);
            dfs(i, n - 1, grid, cellCount);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, grid, cellCount);
            dfs(m - 1, j, grid, cellCount);
        }

        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) {
                    cellCount = 0;
                    dfs(i, j, grid, cellCount);
                    count += cellCount;
                }
            }
        }
        return count;
    }
};