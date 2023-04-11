#include "../stdc++.h"

//class Node {
//public:
//    int val;
//    vector<Node *> neighbors;
//
//    Node() {
//        val = 0;
//        neighbors = vector<Node *>();
//    }
//
//    Node(int _val) {
//        val = _val;
//        neighbors = vector<Node *>();
//    }
//
//    Node(int _val, vector<Node *> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;

        Node *root = new Node(node->val, vector<Node *>());
        map<int, bool> vis;
        map<int, Node *> savedNodes;

        vis[node->val] = true;
        savedNodes[node->val] = root;
        dfs(node, root, vis, savedNodes);

        return root;
    }

    void dfs(Node *originalNode, Node *cpyNode, map<int, bool> &vis, map<int, Node *> &savedNodes) {
        // Copy neighbors
        for (auto n: originalNode->neighbors) {
            if (savedNodes[n->val] == nullptr) {
                savedNodes[n->val] = new Node(n->val, vector<Node *>());
            }

            cpyNode->neighbors.push_back(savedNodes[n->val]);
        }

        // DFS
        auto nei = originalNode->neighbors;
        for (int i = 0; i < nei.size(); i++) {
            if (!vis[nei[i]->val]) {
                vis[nei[i]->val] = true;
                dfs(originalNode->neighbors[i], cpyNode->neighbors[i], vis, savedNodes);
            }
        }
    }
};

class Solution2 {
public:
    unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if(m.count(node))
            return m[node];
        m[node]=new Node(node->val);
        for(auto &e:node->neighbors){
            m[node]->neighbors.push_back(cloneGraph(e));
        }
        return m[node];
    }
};