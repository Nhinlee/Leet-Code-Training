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
    map<int, int> flags;
public:
    // C1: Hash map
    vector<int> findMode(TreeNode *root) {
        vector<int> rs = {};
        int maxx = 0;

        dfs(root);

        for (auto it: flags) {
            if (it.second > maxx) {
                maxx = it.second;
                rs.clear();
                rs.push_back(it.first);
            } else if (it.second == maxx) {
                rs.push_back(it.first);
            }
        }

        return rs;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        flags[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    // C2: BST
    int last = INT_MIN;
    int count = 0;
    int max = 0;
    std::vector<int> modes;

    vector<int> findModeC2(TreeNode *root) {
        traverse(root);
        return modes;
    }

    void traverse(TreeNode *node) {
        if (node == nullptr) return;

        traverse(node->left);

        if (last == node->val) {
            count++;
        } else {
            count = 1;
        }

        if (count > max) {
            max = count;
            modes.clear();
            modes.push_back(node->val);
        } else if (count == max) {
            modes.push_back(node->val);
        }

        last = node->val;

        traverse(node->right);
    }
};