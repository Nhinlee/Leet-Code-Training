#include "../stdc++.h"

class Solution {
public:
    // DFS
    int minScore(int n, vector<vector<int>>& roads) {
        int minS = INT_MAX;
        map<int, vector<int>> edges;
        map<int, bool> visited;
        for (auto r : roads) {
            edges[r[0]].push_back(r[1]);
            edges[r[1]].push_back(r[0]);
        }

        dfs(edges, visited, 1);

        for (auto r : roads) {
            if (visited[r[0]]) {
                minS = min(minS, r[2]);
            }
        }

        return minS;
    }

    void dfs(map<int, vector<int>> &edges, map<int, bool> &visited, int position) {
        visited[position] = true;

        for (auto v : edges[position]) {
            if (visited[v]) continue;
            dfs(edges, visited, v);
        }
    }

    // BFS
    int minScoreV2(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> gr(n+1);
        for(auto edge : roads){
            gr[edge[0]].push_back({edge[1], edge[2]}); // u-> {v, dis}
            gr[edge[1]].push_back({edge[0], edge[2]}); // v-> {u, dis}
        }

        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1); vis[1] = 1;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            for(auto& [v, dis] : gr[node]){
                ans = min(ans, dis);
                if(vis[v]==0){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};