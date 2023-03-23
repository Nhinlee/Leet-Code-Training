#include "../stdc++.h"

class Solution {
public:
    // BFS
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;

        vector<bool> visited(n);
        map<int, vector<int>> edges;
        int rs = 0;

        for (auto c: connections) {
            edges[c[0]].push_back(c[1]);
            edges[c[1]].push_back(c[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                rs++;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int temp = q.front();
                    q.pop();

                    for (auto v: edges[temp]) {
                        if (visited[v]) continue;
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        return rs - 1;
    }
};