#include "../stdc++.h"

class Solution {
private:
    vector<vector<TreeNode *>> memo;

public:
    // C1: back tracking
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        memo = vector<vector<TreeNode *>>();
        vector<TreeNode *> currentPath;
        lowestCommonAncestor(root, p, q, currentPath);

        // Back tracking
        auto path1 = memo[0];
        auto path2 = memo[1];
        int index = min(path1.size() - 1, path2.size() - 1);
        while (index >= 0) {
            if (path1[index] == path2[index]) break;
            index--;
        }

        return path1[index];
    }

    void lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> &currentPath) {
        if (root == nullptr) return;

        currentPath.push_back(root);

        if (root->val == p->val || root->val == q->val) memo.push_back(currentPath);

        lowestCommonAncestor(root->left, p, q, currentPath);
        lowestCommonAncestor(root->right, p, q, currentPath);
        currentPath.pop_back();
    }

    // C2:
    TreeNode *lowestCommonAncestorC2(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right == nullptr) return nullptr;
        if (left != nullptr && right != nullptr) return root;
        return left != nullptr ? right : left;
    }
};