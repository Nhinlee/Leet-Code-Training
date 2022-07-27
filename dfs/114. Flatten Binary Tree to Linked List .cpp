#include "../stdc++.h"

class Solution {
public:
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
};