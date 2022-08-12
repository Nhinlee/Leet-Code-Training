#include "../stdc++.h"

class Solution {
public:
    // C1: Space: O(H), complex: O(H)
    TreeNode *lowestCommonAncestorC1(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> pathP, pathQ;
        BFS(root, p, pathP);
        BFS(root, q, pathQ);
        int n = min(pathP.size(), pathQ.size());
        for (int i = n - 1; i >= 0; i--) {
            if (pathQ[i] == pathP[i]) return pathQ[i];
        }

        return nullptr;
    }

    void BFS(TreeNode *root, TreeNode *node, vector<TreeNode *> &path) {
        if (root == nullptr) return;
        path.push_back(root);
        if (root == node) return;

        if (root->val > node->val) {
            BFS(root->left, node, path);
        } else {
            BFS(root->right, node, path);
        }
    }

    // C2: Space O(1), complex: O(H)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root != nullptr) {
            if (root->val > large) {
                root = root->left;
            } else if (root->val < small) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};