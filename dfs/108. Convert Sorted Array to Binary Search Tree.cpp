#include "../stdc++.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        return sortedArrayToBST(nums, l, r);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);

        return root;
    }

};