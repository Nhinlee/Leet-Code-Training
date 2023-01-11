#include "../stdc++.h"

class Solution {
public:
    // Wrong solution
//    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
//        map<int, set<int>> tree;
//        int minNode = INT_MAX, count = 0;
//        for (auto e: edges) {
//            tree[e[0]].insert(e[1]);
//            minNode = min(minNode, e[0]);
//        }
//
//        dfsClearLeaf(tree, hasApple, minNode);
//
//        dfsCountNode(tree, minNode, count);
//        return count * 2 - 2;
//    }

    // Clear leaf don't have apple
    bool dfsClearLeaf(map<int, set<int>> &tree, vector<bool> &hasApple, int currNode) {
        auto childes = tree[currNode];
        if (childes.empty()) return false;

        bool haveAppleAtChildes = false;
        for (auto c: childes) {
            bool haveApples = dfsClearLeaf(tree, hasApple, c) || hasApple[c];
            if (!haveApples) {
                tree[currNode].erase(c);
            }

            haveAppleAtChildes |= haveApples;
        }

        return haveAppleAtChildes;
    }

    void dfsCountNode(map<int, set<int>> &tree, int currNode, int &count) {
        count++;
        auto childes = tree[currNode];
        if (childes.empty()) return;

        for (auto c: childes) {
            dfsCountNode(tree, c, count);
        }
    }

    // ----------------------------------- Best solution -------------------------------
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            childTime = dfs(child, node, adj, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime || hasApple[child]) totalTime += childTime + 2;
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};

int main() {
    Solution *s = new Solution();
    auto edges = vector<vector<int>>{{2, 6},
                                     {0, 1},
                                     {0, 2},
                                     {1, 4},
                                     {1, 5},
                                     {2, 3}};
    auto hasApple = vector<bool>{false, false, true, false, true, true, false};
    cout << s->minTime(7, edges, hasApple);
}