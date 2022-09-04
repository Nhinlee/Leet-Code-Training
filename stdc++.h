#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "sstream"
#include "queue"
#include <numeric>
#include <set>
#include "regex"
#include <bitset>


using namespace std;


struct TreeNode {
    int val;
    int k;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), k(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), k(1), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {

public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
