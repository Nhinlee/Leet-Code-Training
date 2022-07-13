#include "../stdc++.h"

class Solution {
public:
    int averageOfSubtree(TreeNode *root) {
        int avgCount = 0;
        countAverageNode(root, avgCount);
        return avgCount;
    }

    int sumTree(TreeNode *root, int &countNode) {
        if (root == NULL) return 0;

        countNode++;
        return root->val + sumTree(root->left, countNode) + sumTree(root->right, countNode);
    }

    void countAverageNode(TreeNode *node, int &avgCount) {
        if (node == NULL) return;

        int countNode = 0;
        int sum = sumTree(node, countNode);
        if (sum / countNode == node->val) avgCount++;

        countAverageNode(node->left, avgCount);
        countAverageNode(node->right, avgCount);
    }
};