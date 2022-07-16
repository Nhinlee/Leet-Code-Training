#include "../stdc++.h"

class FindElements {
private:
    map<int, int> elements;

    void dfsToSaveElement(TreeNode *root, int x) {
        if (root == NULL) return;

        root->val = x;
        elements[x]++;

        dfsToSaveElement(root->left, x * 2 + 1);
        dfsToSaveElement(root->right, x * 2 + 2);
    }

public:
    FindElements(TreeNode *root) {
        dfsToSaveElement(root, 0);
    }

    bool find(int target) {
        return elements[target] > 0;
    }
};