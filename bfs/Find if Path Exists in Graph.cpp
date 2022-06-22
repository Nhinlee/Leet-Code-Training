#include "../stdc++.h"


class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        if (source == destination) return true;

        map<int, vector<int>> mapEdges;
        for (auto x: edges) {
            mapEdges[x[0]].push_back(x[1]);
            mapEdges[x[1]].push_back(x[0]);
        }

        vector<bool> flags(n);
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int breadth = q.size();
            for (int _ = 0; _ < breadth; _++) {
                int v = q.front();
                q.pop();

                for (auto x: mapEdges[v]) {
                    if (x == destination) return true;
                    if (!flags[x]) {
                        q.push(x);
                        flags[x] = true;
                    }
                }

            }
        }

        return false;
    }
};