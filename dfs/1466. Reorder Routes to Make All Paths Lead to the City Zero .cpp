#include "../stdc++.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<bool> visited(n);
        map<int, vector<int>> edges;
        set<pair<int, int>> conns;
        int rs = 0;

        for (auto c: connections) {
            edges[c[0]].push_back(c[1]);
            edges[c[1]].push_back(c[0]);

            conns.insert({c[0], c[1]});
        }

        visited[0] = true;
        dfs(edges, visited, conns, 0, rs);

        return rs;
    }

    void dfs(map<int, vector<int>> &edges, vector<bool> &visited, set<pair<int, int>> &conns, int pos, int &count) {
        for (auto v: edges[pos]) {
            if (!visited[v]) {
                visited[v] = true;
                if (conns.count({pos, v}) > 0) {
                    count++;
                }

                dfs(edges, visited, conns, v, count);
            }
        }
    }
};