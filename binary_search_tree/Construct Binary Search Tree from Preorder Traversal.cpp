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
    int i = 0;

    TreeNode *bstFromPreorder(vector<int> &preorder, int bound = INT_MAX) {
        if (i >= preorder.size() || preorder[i] > bound) return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, bound);

        return root;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> arr{8, 5, 1, 7, 10, 12};
    s->bstFromPreorder(arr);
}