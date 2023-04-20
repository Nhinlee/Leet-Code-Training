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

struct NodeInfo {
    int left; // length of longest path ending at node and going left
    int right; // length of longest path ending at node and going right
};

int longestZigZag(TreeNode* root) {
    int ans = 0;
    function<NodeInfo(TreeNode*)> dfs = [&](TreeNode* node) -> NodeInfo {
        if (!node) {
            return {0, 0};
        }
        NodeInfo left = dfs(node->left), right = dfs(node->right);
        int left_val = 1 + right.right, right_val = 1 + left.left;
        ans = max(ans, max(left_val, right_val));
        return {left_val, right_val};
    };
    dfs(root);
    return ans - 1;
}
