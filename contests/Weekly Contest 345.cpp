#include "../stdc++.h"

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> a = vector<int>(n);
        int i = 0, t = 1;
        a[i] = 1;

        while (a[i] <= 1) {
            int next = (i + t * k) % n;
            a[next]++;
            i = next;
            t++;
        }

        vector<int> rs;
        for (int j = 1; j <= n; j++) {
            if (a[j - 1] == 0) {
                rs.push_back(j);
            }
        }
        return rs;
    }

    bool doesValidArrayExist(vector<int> &derived) {
        int n = derived.size();
        for (int original_0: {0, 1}) {
            vector<int> original(n);
            original[0] = original_0;
            for (int i = 1; i < n; i++) {
                original[i] = derived[i - 1] ^ original[i - 1];
            }
            original[n - 1] = derived[n - 1] ^ original[0];

            // Double check origins
            for (int i = 0; i < n - 1; i++) {
                if (original[i] ^ original[i + 1] != derived[i]) return false;
            }
            if (original[n - 1] ^ original[0] != derived[n - 1]) return false;
        }

        return true;
    }

    // https://leetcode.com/contest/weekly-contest-345/problems/maximum-number-of-moves-in-a-grid/
    vector<vector<int>> dp;
    int maxMoves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), rs = 0;
        dp = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            rs = max(dfs(grid, i, 0, n, m), rs);
        }

        return rs;
    }

    int dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if (i >= n || j >= m) return 0;

        if (dp[i][j] > 0) return dp[i][j];

        int rs = 0;

        int colNext = j + 1;
        if (colNext < m) {
            if (i - 1 >= 0 && grid[i - 1][colNext] > grid[i][j]) {
                rs = max(rs, 1 + dfs(grid, i - 1, colNext, n, m));
            }

            if (grid[i][colNext] > grid[i][j]) {
                rs = max(rs, 1 + dfs(grid, i, colNext, n, m));
            }

            if (i + 1 < n && grid[i + 1][colNext] > grid[i][j]) {
                rs = max(rs, 1 + dfs(grid, i + 1, colNext, n, m));
            }
        }

        dp[i][j] = rs;
        return rs;
    }


    /// https://leetcode.com/contest/weekly-contest-345/problems/count-the-number-of-complete-components/
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u, vector<int>& comp) {
        visited[u] = true;
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, visited, v, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int u = 0; u < n; u++) {
            if (!visited[u]) {
                vector<int> comp;
                dfs(adj, visited, u, comp);
                bool is_complete = true;
                for (int i = 0; i < comp.size(); i++) {
                    for (int j = i+1; j < comp.size(); j++) {
                        int u = comp[i], v = comp[j];
                        if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
                            is_complete = false;
                            break;
                        }
                    }
                    if (!is_complete) {
                        break;
                    }
                }
                if (is_complete) {
                    count++;
                }
            }
        }
        return count;
    }
};

//int main() {
//    vector<vector<int>> nums = {{0, 2},
//                                {1, 2},
//                                {3, 1},
//                                {1, 1},
//                                {2, 1}};
//    vector<int> d = vector<int>{1, 1, 0};
//    string t = "aaaaab";
//    Solution *s = new Solution();
//    s->doesValidArrayExist(d);
//
//    return 0;
//}