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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, uint64_t>> q;
        q.push({root, 0});
        int max_width = 1;
        while (!q.empty()) {
            int size = q.size();
            uint64_t leftmost = q.front().second;
            uint64_t rightmost = leftmost;
            for (int i = 0; i < size; i++) {
                auto [node, pos] = q.front();
                q.pop();
                rightmost = pos;
                if (node->left) {
                    q.push({node->left, 2 * pos});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos + 1});
                }
            }
            max_width = max(max_width, static_cast<int>(rightmost - leftmost + 1));
        }
        return max_width;
    }

};