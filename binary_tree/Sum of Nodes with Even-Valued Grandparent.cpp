#include "../stdc++.h"

class Solution {
public:
    int sumEvenGrandparent(TreeNode *root) {
        if (root == NULL) return 0;

        int sum = 0;
        if (root->val % 2 == 0) sum += sumChilds(root);
        sum += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        return sum;
    }

    int sumChilds(TreeNode *root) {
        // if(root == NULL) return 0;
        int sum = 0;
        if (root->left != NULL) {
            sum += getValIfCan(root->left->left) + getValIfCan(root->left->right);
        }
        if (root->right != NULL) {
            sum += getValIfCan(root->right->left) + getValIfCan(root->right->right);
        }
        return sum;
    }

    int getValIfCan(TreeNode *node) {
        return node == NULL ? 0 : node->val;
    }

    // C2
    int sumEvenGrandparentC2(TreeNode* root, int p = 1, int gp = 1) {
        return root ? sumEvenGrandparentC2(root->left, root->val, p)
                      + sumEvenGrandparentC2(root->right, root->val, p)
                      + (gp % 2 ? 0 : root->val)  : 0;
    }
};