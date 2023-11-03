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
private:
    int rs;
public:
    int averageOfSubtree(TreeNode *root) {
        dfs(root);
        return rs;
    }

    pair<int, int> dfs(TreeNode *node) {
        if (node == nullptr) return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // check condition
        auto sum = left.first + right.first + node->val;
        auto count = left.second + right.second + 1;
        if (sum / count == node->val) {
            rs++;
        }

        return {sum, count};
    }
};