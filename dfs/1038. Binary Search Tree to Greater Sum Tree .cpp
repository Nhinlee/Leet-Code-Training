#include "../stdc++.h"

class Solution {
public:
    TreeNode *bstToGst(TreeNode *root) {
        int currSum = 0;
        calculateToGST(root, currSum);
        return root;
    }

    void calculateToGST(TreeNode *root, int &currentSum) {
        if (root == nullptr) return;

        calculateToGST(root->right, currentSum);

        int temp = currentSum + root->val;
        root->val += currentSum;
        currentSum = temp;

        calculateToGST(root->left, currentSum);
    }
};