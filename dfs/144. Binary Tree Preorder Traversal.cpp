#include "../stdc++.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // C1: Recursive
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> rs;
        dfs(root, rs);
        return rs;
    }

    void dfs(TreeNode *root, vector<int> &list) {
        if (root == nullptr) return;

        list.push_back(root->val);
        dfs(root->left, list);
        dfs(root->right, list);
    }

    // C2: Stack (Non recursive)
    vector<int> preorderTraversalC2(TreeNode *root) {
        if (root == nullptr) return vector<int>{};

        vector<int> rs;
        vector<TreeNode *> st;
        st.push_back(root);

        while (!st.empty()) {
            auto node = st.back();
            st.pop_back();
            rs.push_back(node->val);

            if (node->right != nullptr) st.push_back(node->right);
            if (node->left != nullptr) st.push_back(node->left);
        }

        return rs;
    }
};