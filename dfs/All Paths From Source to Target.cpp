#include "../stdc++.h"

class Solution {
private:
    vector<vector<int>> paths;
    vector<bool> flags;


public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        flags = vector<bool>(graph.size(), false);
        vector<int> currentPath{0};
        dfsGraph(graph, currentPath, 0);
        return paths;
    }

    void dfsGraph(vector<vector<int>> &graph, vector<int> &currentPath, int index) {
        //
        if (index == graph.size() - 1) {
            paths.push_back(currentPath);
        }

        //
        for (auto x: graph[index]) {
            if (!flags[x]) {
                flags[x] = true;
                currentPath.push_back(x);

                dfsGraph(graph, currentPath, x);

                flags[x] = false;
                currentPath.pop_back();
            }
        }
    }
};