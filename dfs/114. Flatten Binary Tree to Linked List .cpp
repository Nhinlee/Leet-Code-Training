#include "../stdc++.h"

class Solution {
private:
    TreeNode *prevNode;
public:
    // C1: Space: O(n), complexity: O(n)
    void flatten(TreeNode *root) {
        if (root == nullptr) return;

        vector<TreeNode *> saver;
        dfs(root, saver);

        int n = saver.size();
        for (int i = 0; i < n - 1; i++) {
            saver[i]->left = nullptr;
            saver[i]->right = saver[i + 1];
        }
        saver[n - 1]->left = nullptr;
        saver[n - 1]->right = nullptr;
    }

    void dfs(TreeNode *root, vector<TreeNode *> &saver) {
        if (root == nullptr) return;

        saver.push_back(root);
        dfs(root->left, saver);
        dfs(root->right, saver);
    }

    // C1: Space: O(1), complexity: O(n)
    void flattenC2(TreeNode *root) {
        if (root == nullptr) return;

        flatten(root->right);
        flatten(root->left);

        root->left = nullptr;
        root->right = prevNode;
        // Save current node to serve
        prevNode = root;
    }
};