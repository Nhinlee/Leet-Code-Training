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
    int deepestLeavesSum(TreeNode *root) {
        int maxHeight = maxHeightOfTree(root);
        int deepestSum = 0;
        dfsDeepestLeavesSum(root, 1, maxHeight, deepestSum);
        return deepestSum;
    }

    int maxHeightOfTree(TreeNode *root) {
        if (root == NULL) return 0;
        return 1 + max(maxHeightOfTree(root->left), maxHeightOfTree(root->right));
    }

    void dfsDeepestLeavesSum(TreeNode *root, int deep, int maxHeight, int &sum) {
        if (root == NULL) return;
        if (deep == maxHeight) sum += root->val;

        dfsDeepestLeavesSum(root->left, deep + 1, maxHeight, sum);
        dfsDeepestLeavesSum(root->right, deep + 1, maxHeight, sum);
    }
};