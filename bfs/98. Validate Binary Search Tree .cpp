#include "../stdc++.h"

class Solution {
public:
    // C1
    bool isValidBSTC1(TreeNode *root) {
        return isValidBSTC1(root, nullptr, nullptr);
    }

    bool isValidBSTC1(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == nullptr) return true;
        if (minNode != nullptr && minNode->val >= root->val) return false;
        if (maxNode != nullptr && maxNode->val <= root->val) return false;

        return isValidBSTC1(root->left, minNode, root) && isValidBSTC1(root->right, root, maxNode);
    }

};