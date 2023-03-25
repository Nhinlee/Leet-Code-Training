#include "../stdc++.h"

class Solution {
public:
    // BFS
    long long countPairs(int n, vector<vector<int>> &edges) {
        long long rs = 0;
        long long total = n;
        vector<bool> visited(n);
        map<int, vector<int>> rounds;

        for (auto e: edges) {
            rounds[e[0]].push_back(e[1]);
            rounds[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // bfs for to all the graph and count how many node in there
                visited[i] = true;
                queue<int> q;
                long long count = 1;

                q.push(i);
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (auto v: rounds[curr]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                            count++;
                        }
                    }
                }

                // => calculate rs
                rs += count * (total - count);
                total -= count;
            }
        }

        return rs;
    }
};