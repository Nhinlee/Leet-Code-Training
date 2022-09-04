#include "../stdc++.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        auto res = vector<vector<int>>();
        int n = matrix.size();
        int m = matrix[0].size();
        auto pacific = vector<vector<bool>>(n, vector<bool>(m));
        auto atlantic = vector<vector<bool>>(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            dfs(matrix, pacific, -1, i, 0);
            dfs(matrix, atlantic, -1, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(matrix, pacific, -1, 0, i);
            dfs(matrix, atlantic, -1, n - 1, i);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back(vector<int>{i, j});
        return res;
    }

    vector<vector<int>> dir = vector<vector<int>>{{0,  1},
                                                  {0,  -1},
                                                  {1,  0},
                                                  {-1, 0}};

    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int height, int x, int y) {
        int n = matrix.size(), m = matrix[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || matrix[x][y] < height)
            return;
        visited[x][y] = true;
        for (auto d: dir) {
            dfs(matrix, visited, matrix[x][y], x + d[0], y + d[1]);
        }
    }
};