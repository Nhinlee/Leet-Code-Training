#include "../stdc++.h"

class Solution {
private:
    vector<vector<bool>> visited;
public:
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size(), col = grid[0].size();
        int countIsland = 0;
        visited = vector<vector<bool>>(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    countIsland++;
                    visit(grid, i, j);
                }
            }
        }

        return countIsland;
    }

    void visit(vector<vector<char>> &grid, int i, int j) {
        int row = grid.size(), col = grid[0].size();
        visited[i][j] = true;
        int dx = i, dy = j;

        dx = i - 1;
        if (dx >= 0 && !visited[dx][dy] && grid[dx][dy] == '1') {
            visit(grid, dx, dy);
        }
        dx = i + 1;
        if (dx < row && !visited[dx][dy] && grid[dx][dy] == '1') {
            visit(grid, dx, dy);
        }
        dy = j - 1;
        dx = i;
        if (dy >= 0 && !visited[dx][dy] && grid[dx][dy] == '1') {
            visit(grid, dx, dy);
        }
        dy = j + 1;
        if (dy < col && !visited[dx][dy] && grid[dx][dy] == '1') {
            visit(grid, dx, dy);
        }
    }
};