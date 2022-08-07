#include "../stdc++.h"

class Solution {
private:
    vector<vector<int>> paths;
    vector<bool> targetMemo;


public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        targetMemo = vector<bool>(graph.size(), false);
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
            if (!targetMemo[x]) {
                targetMemo[x] = true;
                currentPath.push_back(x);

                dfsGraph(graph, currentPath, x);

                targetMemo[x] = false;
                currentPath.pop_back();
            }
        }
    }
};