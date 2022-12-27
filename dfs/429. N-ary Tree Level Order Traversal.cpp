#include "../stdc++.h"


class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> rs = vector<vector<int>>();
        traverse(root, 0, rs);
        return rs;
    }

    void traverse(Node *root, int depth, vector<vector<int>> &rs) {
        if (root == nullptr) return;

        if (rs.size() == depth) {
            rs.emplace_back();
        }

        rs[depth].push_back(root->val);
        for (auto c: root->children) {
            traverse(c, depth + 1, rs);
        }
    }

    TreeNode *pruneTree(TreeNode *root) {
        traverseAndDrop(root);
        if (root != nullptr && root->left == nullptr && root->right == nullptr && root->val == 0) return nullptr;
        return root;
    }

    bool traverseAndDrop(TreeNode *root) {
        if (root == nullptr) return true;

        auto l = traverseAndDrop(root->left);
        auto r = traverseAndDrop(root->right);

        if (l) root->left = nullptr;
        if (r) root->right = nullptr;

        return l && r && root->val == 0;
    }

    // https://leetcode.com/problems/construct-string-from-binary-tree/
    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";

        string temp = "";
        
    }
};

//int main() {
//    Solution *s = new Solution();
//    Node *root = new Node();
//    s->levelOrder(root);
//}