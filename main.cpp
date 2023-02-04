#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "sstream"
#include "queue"
#include <numeric>
#include <set>

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

class Solution {
public:

    // https://leetcode.com/problems/divisor-game/
    bool divisorGame(int n) {
        return n % 2 == 0;
    }

    // https://leetcode.com/problems/contains-duplicate-ii/
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> flags;
        for (int i = 0; i < nums.size(); i++) {
            if (flags.count(nums[i]) > 0) {
                if (abs(flags[nums[i]] - i) <= k) {
                    return true;
                }
            }

            flags[nums[i]] = i;
        }

        return false;
    }

    // https://leetcode.com/problems/set-mismatch/
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        int dup = -1;
        int loss = -1;

        vector<int> flags(n + 1);

        for (int i = 0; i < n; i++) {
            flags[nums[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (flags[i] > 1) {
                dup = i;
            }
            if (flags[i] == 0) {
                loss = i;
            }
        }

        return vector<int>{dup, loss};
    }

    // https://leetcode.com/problems/isomorphic-strings/
    bool isIsomorphic(string s, string t) {
        map<char, char> flagsS;
        map<char, char> flagsT;
        for (int i = 0; i < s.size(); i++) {
            if (flagsT.count(t[i]) > 0 && flagsT[t[i]] != s[i]) return false;
            flagsT[t[i]] = s[i];

            if (flagsS.count(s[i]) > 0 && flagsS[s[i]] != t[i]) return false;
            flagsS[s[i]] = t[i];
        }
        return true;
    }

    // https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        map<int, int> flags;
        vector<int> sortedNums = nums;
        vector<int> rs;
        int n = nums.size();

        sort(sortedNums.begin(), sortedNums.end());
        for (int i = n - 1; i >= n - k; i--) {
            flags[sortedNums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (flags[nums[i]] > 0) {
                flags[nums[i]]--;
                rs.push_back(nums[i]);
            }
        }

        return rs;
    }

    // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
    string removeDuplicates(string s) {
        int i = 0;
        int n = s.length();

        for (int j = 0; j < n; j++, i++) {
            s[i] = s[j];
            if (i > 0 && s[i] == s[i - 1]) {
                i -= 2;
            }
        }

        return s.substr(0, i);
    }

    void reset(int &a) {
        a = 0;
    }

    void increment(int &a) {
        a++;
    }

    void transfer(int &a, int &b) {
        b = a;
        a = -1;
    }

    void sum(int &a, int &b) {
        int c = 0;
        while (c != b) {
            increment(c);
            increment(a);
        }
    }

    int divideA(int &a) {
        int b, c, d, e, f;
        reset(b);
        reset(c);
        reset(d);
        reset(e);
        reset(f);

        while (b + c != a) {
            transfer(c, d);
            transfer(b, c);
            while (b != d) {
                b++;
            }
            b++;
        }

        return c;
    }

    // https://leetcode.com/problems/duplicate-zeros/

    // C2: Two pointer
    void duplicateZerosC2(vector<int> &arr) {
        // Count the 0 in the arr and add space for arr
        int originalSize = arr.size();
        for (int i = 0; i < originalSize; i++) {
            if (arr[i] == 0) arr.push_back(0);
        }

        // Create 2 pointers to copy
        int i = arr.size() - 1;
        int j = originalSize - 1;
        while (j >= 0) {
            if (arr[j] == 0) {
                arr[i--] = 0;
                arr[i--] = 0;
            } else {
                arr[i--] = arr[j];
            }
            j--;
        }

        while (arr.size() > originalSize) arr.pop_back();
    }

    // C1
    void duplicateZeros(vector<int> &arr) {
        vector<int> rs;
        for (auto x: arr) {
            if (x == 0) {
                rs.push_back(x);
                rs.push_back(x);
            } else {
                rs.push_back(x);
            }
            if (rs.size() > arr.size()) {
                rs.pop_back();
                arr = rs;
                break;
            } else if (rs.size() == arr.size()) {
                arr = rs;
                break;
            }
        }
    }

    // https://leetcode.com/problems/construct-string-from-binary-tree/
    string tree2strC2(TreeNode *root) {
        if (root == NULL) return "";

        vector<TreeNode *> st;
        set<TreeNode *> visited;
        st.push_back(root);
        string rs = "";

        while (!st.empty()) {
            TreeNode *curr = st.back();

            if (visited.find(curr) != visited.end()) {
                rs += ")";
                st.pop_back();
            } else {
                visited.insert(curr);
                rs += "(" + to_string(curr->val);

                if (curr->left == NULL && curr->right != NULL) rs += "()";

                if (curr->right != NULL) st.push_back(curr->right);
                if (curr->left != NULL) st.push_back(curr->left);
            }
        }

        return rs.substr(1, rs.size() - 2);
    }

    string tree2str(TreeNode *root) {
        if (root == NULL) return "";
        if (root->left == NULL && root->right == NULL) {
            return to_string(root->val);
        }

        string leftStr = "(" + tree2str(root->left) + ")";
        string r = tree2str(root->right);
        string rightStr = r.empty() ? "" : "(" + r + "";

        return to_string(root->val) + leftStr + rightStr;
    }

    // https://leetcode.com/problems/binary-tree-tilt/
    int tilt = 0;

    int findTilt(TreeNode *root) {
        DFSSum(root);
        return tilt;
    }

    int DFSSum(TreeNode *root) {
        if (root == NULL) return 0;

        int sumLeft = DFSSum(root->left);
        int sumRight = DFSSum(root->right);
        tilt += abs(sumLeft - sumRight);

        return root->val + sumLeft + sumRight;
    }

    // https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
    bool findTarget(TreeNode *root, int k) {
        vector<int> arr;
        sortArrayFromBinaryTree(root, arr);
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int target = k - arr[i];
            int l = 0;
            int r = n - 1;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] == target && i != mid) return true;
                if (arr[mid] < target) l = mid + 1; else r = mid - 1;
            }
        }
        return false;
    }

    void sortArrayFromBinaryTree(TreeNode *root, vector<int> &arr) {
        if (root == NULL) return;

        sortArrayFromBinaryTree(root->left, arr);
        arr.push_back(root->val);
        sortArrayFromBinaryTree(root->right, arr);
    }

    // https://leetcode.com/problems/fair-candy-swap/solution/
    vector<int> fairCandySwapC2(vector<int> &aliceSizes, vector<int> &bobSizes) {
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumBob - sumAlice) / 2;

        set<int> setB;
        for (auto x: bobSizes) setB.insert(x);

        for (auto x: aliceSizes) {
            if (setB.find(x + delta) != setB.end()) return vector<int>{x, x + delta};
        }

        return vector<int>{0, 0};
    }

    // https://leetcode.com/problems/fair-candy-swap/
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumAlice - sumBob) / 2;

        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        for (int i = 0; i < aliceSizes.size(); i++) {
            int l = 0;
            int r = bobSizes.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int temp = (aliceSizes[i] - bobSizes[mid]) - delta;
                if (temp == 0) return vector<int>{aliceSizes[i], bobSizes[mid]};

                if (delta < 0) {
                    if (temp > 0) l = mid + 1; else r = mid - 1;
                } else {
                    if (temp > 0) r = mid - 1; else l = mid + 1;
                }
            }
        }

        return vector<int>{0, 0};
    }


    // https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
    int specialArray(vector<int> &nums) {
        int l = 1;
        int r = nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            int countGreater = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= mid) countGreater++;
            }

            if (countGreater == mid) return mid;
            if (countGreater > mid) l = mid + 1; else r = mid - 1;
        }
        return -1;
    }

    // https://leetcode.com/problems/binary-tree-postorder-traversal/
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> rs;
        postorderTraversal(root, rs);

        return rs;
    }

    void postorderTraversal(TreeNode *root, vector<int> &order) {
        if (root == NULL) return;

        postorderTraversal(root->left, order);
        postorderTraversal(root->right, order);
        order.push_back(root->val);
    }

    // https://leetcode.com/problems/binary-tree-paths/
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> rs;
        if (root == NULL) return rs;
        string binaryPathStr = "";
        binaryPathStr = to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            rs.push_back(binaryPathStr);
            return rs;
        }

        getBinaryTreePath(root, rs, binaryPathStr);
        return rs;
    }

    void getBinaryTreePath(TreeNode *root, vector<string> &rs, string currentPath) {
        if (root == NULL) return;

        currentPath += "->" + to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            rs.push_back(currentPath);
        }

        getBinaryTreePath(root->left, rs, currentPath);
        getBinaryTreePath(root->right, rs, currentPath);
    }

    // https://leetcode.com/problems/leaf-similar-trees/
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        getLeafOrder(root1, leafs1);
        getLeafOrder(root2, leafs2);

        if (leafs1.size() != leafs2.size()) return false;
        for (int i = 0; i < leafs1.size(); i++) {
            if (leafs1[i] != leafs2[i]) return false;
        }
        return true;
    }

    void getLeafOrder(TreeNode *root, vector<int> &leafs) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            leafs.push_back(root->val);
            return;
        }

        getLeafOrder(root->left, leafs);
        getLeafOrder(root->right, leafs);
    }

    // https://leetcode.com/problems/average-of-levels-in-binary-tree/
    // C2: DFS
    vector<double> averageOfLevelsC2(TreeNode *root) {
        vector<double> sum;
        vector<int> count;

        // TODO:
    }


    // C1: BFS
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> averages;
        if (root == NULL) return averages;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int breadth = q.size();
            double sum = 0;
            int nums = 0;
            for (int _ = 0; _ < breadth; _++) {
                TreeNode *curr = q.front();
                q.pop();

                sum += curr->val;
                nums++;

                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            averages.push_back(sum / nums);
        }

        return averages;
    }

    // https://leetcode.com/problems/minimum-moves-to-convert-string/
    int minimumMoves(string s) {
        int i = 0;
        int n = s.size();
        int rs = 0;
        while (i < n) {
            if (s[i] == 'O') {
                i++;
            } else if (s[i] == 'X') {
                rs++;
                i += 3;
            }
        }

        return rs;
    }

    // https://leetcode.com/problems/longest-palindrome/
    int longestPalindrome(string s) {
        map<char, int> flags;
        for (int i = 0; i < s.size(); i++) {
            flags[s[i]]++;
        }

        int count = 0;
        map<char, int>::iterator it;
        it = flags.begin();
        while (it != flags.end()) {
            count += it->second / 2 * 2;
            it++;
        }

        return count == s.size() ? count : count + 1;
    }

    // https://leetcode.com/problems/largest-perimeter-triangle/
    int largestPerimeter(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            if (isRectangle(nums[i], nums[i - 1], nums[i - 2])) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }

    bool isRectangle(int a, int b, int c) {
        return a + b > c && a + c > b && b + c > a;
    }


    // https://leetcode.com/problems/largest-odd-number-in-string/
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0) {
            if (num[i] % 2 != 0) {
                break;
            }
            i--;
        }
        if (i < 0) return "";
        return num.substr(0, i + 1);
    }

    // https://leetcode.com/problems/univalued-binary-tree/
    // C2: Iterative - BFS
    bool isUnivalTreeC2(TreeNode *root) {
        if (root == NULL) return true;
        int value = root->val;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL) continue;
            if (curr->val != value) return false;

            q.push(curr->left);
            q.push(curr->right);
        }

        return true;
    }

    // C1: DFS - recursive
    bool isUnivalTree(TreeNode *root) {
        if (root == NULL) return true;
        return isUnivalTree(root, root->val);
    }

    bool isUnivalTree(TreeNode *root, int value) {
        if (root == NULL) return true;
        if (root->val != value) return false;

        return isUnivalTree(root->left, value) && isUnivalTree(root->right, value);
    }

    // https://leetcode.com/problems/island-perimeter/
    // C1:
    int islandPerimeter(vector<vector<int>> &grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (i - 1 < 0 || grid[i - 1][j] == 0) perimeter++;
                    if (i + 1 == grid.size() || grid[i + 1][j] == 0) perimeter++;

                    if (j - 1 < 0 || grid[i][j - 1] == 0) perimeter++;
                    if (j + 1 == grid[i].size() || grid[i][j + 1] == 0) perimeter++;
                }
            }
        }
        return perimeter;
    }

    // https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

    // C2: BFS solution
    int maxDepthC2(Node *root) {
        if (root == NULL) return 0;
        queue<Node *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;

            int breadth = q.size();
            for (int i = 0; i < breadth; i++) {
                Node *current = q.front();
                q.pop();

                for (auto node: current->children) {
                    q.push(node);
                }
            }
        }

        return depth;
    }

    // C1: recursive DFS
    int maxDepth(Node *root) {
        if (root == NULL) return 0;
        if (root->children.empty()) return 1;
        //

        int maxD = 0;
        for (auto node: root->children) {
            int tempMax = maxDepth(node);
            maxD = max(maxD, tempMax);
        }

        return maxD + 1;
    }

    // https://leetcode.com/problems/invert-binary-tree/
    // C2: iterative
    TreeNode *invertTreeC2(TreeNode *root) {
        if (root == NULL) return root;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *current = q.front();
            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
            q.pop();
        }

        return root;
    }

    // C1: recursive
    TreeNode *invertTree(TreeNode *root) {
        // Break condition
        if (root == NULL) return NULL;

        // DFS
        TreeNode *leftNode = invertTree(root->left);
        TreeNode *rightNode = invertTree(root->right);

        // Assign swap
        root->left = rightNode;
        root->right = leftNode;

        return root;
    }

    bool isLeftNode(TreeNode *node) {
        if (node == NULL) return false;
        return node->left == NULL && node->right == NULL;
    }

    void swapChildNode(TreeNode *root) {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    // https://leetcode.com/problems/fibonacci-number/
    // C1 - O(n)
    int fib(int n) {
        int f1 = 0, f2 = 1, f3;
        if (n == 0) return 0;

        for (int i = 2; i <= n; i++) {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }

    // https://leetcode.com/problems/counting-bits/
    // C2
    vector<int> countBits2(int n) {
        vector<int> ans;

        // iterating fromt 0 to n
        for (int i = 0; i <= n; i++) {
            // sum is initialised as 0
            int sum = 0;
            int num = i;
            // while num not equals zero
            while (num != 0) {
                // we have to count 1's in binary representation of i, therefore % 2
                sum += num % 2;
                num = num / 2;
            }
            // add sum to ans vector
            ans.push_back(sum);
        }
        // return
        return ans;
    }

    // https://leetcode.com/problems/counting-bits/
    // C1
    vector<int> countBits(int n) {
        vector<int> rs;
        vector<int> flags;

        for (int i = 0; i <= n; i++) {
            int temp = i;
            if (isPowersOf2(temp)) {
                flags.push_back(i);
                rs.push_back(1);
                continue;
            }
            int bit1 = 0;
            int j = flags.size();
            while (j > 0) {
                if (temp >= flags[j - 1]) {
                    temp -= flags[j - 1];
                    bit1++;
                }
                j--;
            }
            //
            rs.push_back(bit1 + temp);
        }
        return rs;
    }

    bool isPowersOf2(int n) {
        if (n <= 1) return false;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                return false;
            }
        }
        return n == 1;
    }

    // https://leetcode.com/problems/most-common-word/
    string mostCommonWord(string paragraph, vector<string> &banned) {
        int i, j;
        i = j = 0;
        while (j < paragraph.size()) {
            if (paragraph[j] < 'a' || paragraph[j] > 'z') {
                istringstream iss('a b c');
            }
            j++;
        }
    }

    // https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
    bool areAlmostEqual(string s1, string s2) {
        // Hash
        map<char, int> flags;
        int countDiff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                countDiff++;
                flags[s1[i]]++;
                flags[s2[i]]--;
            }
            if (countDiff > 2) return false;
        }

        // Check zeros map
        map<char, int>::iterator it = flags.begin();
        while (it != flags.end()) {
            if (it->second != 0) return false;
            it++;
        }
        return true;
    }

    // https://leetcode.com/problems/number-of-equivalent-domino-pairs/
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        // Hash table
        map<int, int> flags;
        for (int i = 0; i < dominoes.size(); i++) {
            int first = dominoes[i][0];
            int second = dominoes[i][1];
            flags[min(first, second) * 10 + max(first, second)]++;
        }

        // Get pair result
        int count = 0;
        map<int, int>::iterator it = flags.begin();
        while (it != flags.end()) {
            count += (it->second) * (it->second - 1) / 2;
            //
            it++;
        }

        return count;
    }

    // https://leetcode.com/problems/n-th-tribonacci-number/
    int tribonacci(int n) {
        vector<int> f;
        int k = 4;
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        f[3] = 2;

        if (n < 4) return f[n];
        while (k <= n) {
            f[0] = f[1];
            f[1] = f[2];
            f[2] = f[3];
            f[3] = f[0] + f[1] + f[2];
            k++;
        }

        return f[3];
    }

    // https://leetcode.com/problems/lemonade-change/
    bool lemonadeChange(vector<int> &bills) {
        int c5 = 0, c10 = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                c5++;
            } else if (bills[i] == 10) {
                c10++;
                c5--;
            } else {
                if (c10 > 0) {
                    c10--;
                    c5--;
                } else {
                    c5 -= 3;
                }
            }

            if (c10 < 0 || c5 < 0) return false;
        }

        return true;
    }

    // https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0;
        while (i < n && k > 0 && nums[i] < 0) {
            nums[i] *= -1;
            k--;
            i++;
        }

        int minIndex = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) minIndex = i;
        }
        nums[minIndex] *= pow(-1, k);


        return accumulate(nums.begin(), nums.end(), 0);
    }

    // https://leetcode.com/problems/flood-fill/

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        fillColor(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void fillColor(vector<vector<int>>
                   &image,
                   int i,
                   int j,
                   int originColor,
                   int newColor
    ) {
        if (i < 0 || i >= image.size()) return;
        if (j < 0 || j >= image[0].size()) return;
        if (image[i][j] != originColor) return;

        image[i][j] = newColor;

        fillColor(image, i - 1, j, originColor, newColor);
        fillColor(image, i + 1, j, originColor, newColor);
        fillColor(image, i, j - 1, originColor, newColor);
        fillColor(image, i, j + 1, originColor, newColor);
    }

    // https://leetcode.com/problems/minimum-absolute-difference-in-bst/
    int getMinimumDifference(TreeNode *root) {
        vector<int> a;

        getSortedArrFromBST(root, a);

        int mi = abs(a[1] - a[0]);
        for (int i = 1; i < a.size(); i++) {
            mi = min(mi, a[i] - a[i - 1]);
        }

        return mi;
    }

    void getSortedArrFromBST(TreeNode *root, vector<int> &a) {
        if (root == NULL) return;

        getSortedArrFromBST(root->left, a);
        a.push_back(root->val);
        getSortedArrFromBST(root->right, a);
    }

    // https://leetcode.com/problems/sum-of-left-leaves/
    int sumOfLeftLeaves(TreeNode *root) {
        int sumLeftLeaves = 0;
        sumOfLeftLeaves(root, sumLeftLeaves);

        return sumLeftLeaves;
    }

    void sumOfLeftLeaves(TreeNode *root, int &sumLeftLeaves) {
        if (root == NULL) return;

        sumOfLeftLeaves(root->left, sumLeftLeaves);
        sumOfLeftLeaves(root->right, sumLeftLeaves);

        if (isHaveLeftLeave(root)) {
            sumLeftLeaves += root->left->val;
        }
    }

    bool isHaveLeftLeave(TreeNode *root) {
        if (root == NULL || root->left == NULL) return false;
        return root->left->left == NULL && root->left->right == NULL;
    }

    // https://leetcode.com/problems/cousins-in-binary-tree/
    bool isCousins(TreeNode *root, int x, int y) {
        queue<TreeNode *> q;
        if (root == NULL) return false;
        q.push(root);

        while (!q.empty()) {
            int breadth = q.size();
            int isX = 0, isY = 0;

            for (int _ = 0; _ < breadth; _++) {
                TreeNode *curr = q.front();
                q.pop();

                if (isChilds(curr, x, y)) return false;

                if (curr->val == x) { isX++; }
                if (curr->val == y) { isY++; }

                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
            }

            if (isX && isY) return true;
        }

        return false;
    }

    bool isChilds(TreeNode *root, int x, int y) {
        if (root == NULL || root->left == NULL || root->right == NULL) return false;
        int valL = root->left->val;
        int valR = root->right->val;
        return (valL == x && valR == y) || (valL == y && valR == x);
    }

    // https://leetcode.com/problems/binary-search/
    int search(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] > target) r = mid - 1; else l = mid + 1;
        }

        return -1;
    }

    // https://leetcode.com/problems/guess-number-higher-or-lower/
    int guess(int num) {

    }

    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (guess(mid) == 0) return mid;
            if (guess(mid) == 1) l = mid + 1; else r = mid - 1;
        }

        return -1;
    }


    // https://leetcode.com/problems/search-insert-position/
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] > target) r = mid - 1; else l = mid + 1;
        }

        if (nums[l] < target) l++;
        return l;
    }

    // https://leetcode.com/problems/peak-index-in-a-mountain-array/
    int peakIndexInMountainArray(vector<int> &arr) {
        int l = 1;
        int r = arr.size() - 2;
        while (l < r) {
            int mid = (l + r) / 2;
            if (isMountainPeek(arr, mid)) return mid;

            if (arr[mid + 1] > arr[mid]) l = mid + 1; else r = mid - 1;
        }

        return -1;
    }

    bool isMountainPeek(vector<int> &arr, int i) {
        return arr[i] > arr[i - 1] && arr[i] > arr[i + 1];
    }

    // https://leetcode.com/problems/diameter-of-binary-tree/
    int diameterOfBinaryTree(TreeNode *root) {
        if (root == NULL) return 0;
        int rootPathD = getMaxHeightOfBT(root->left) + getMaxHeightOfBT(root->right);
        int maxL = diameterOfBinaryTree(root->left);
        int maxR = diameterOfBinaryTree(root->right);

        return max(max(maxL, maxR), rootPathD);
    }

    int getMaxHeightOfBT(TreeNode *root) {
        if (root == NULL) return 0;
        return max(getMaxHeightOfBT(root->left), getMaxHeightOfBT(root->right)) + 1;
    }

    // https://leetcode.com/problems/valid-palindrome-ii/
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return isPalindrome(s.substr(i + 1, j - i))
                       || isPalindrome(s.substr(i, j - i));
            }
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // https://leetcode.com/problems/make-the-string-great/
    string makeGood(string s) {
        int i = 0, j = i + 1, n = s.length();
        string rs;
        vector<bool> flags(n);
        while (i < n - 1) {
            while (isGoodStrPair(s, flags, i, j) && j <= n - 1) {
                flags[i] = true;
                flags[j] = true;

                while (i > 0 && flags[i]) i--;
                if (!flags[i]) j++; else break;
            }
            i = j;
            j += 1;
        }

        for (i = 0; i < n; i++) {
            if (!flags[i]) rs += s[i];
        }
        return rs;
    }

    bool isGoodStrPair(string s, vector<bool> &flags, int i, int j) {
        return abs(s[i] - s[j]) == 32 && !flags[i] && !flags[j];
    }

    // https://leetcode.com/problems/reduce-array-size-to-the-half/
    int minSetSize(vector<int> &arr) {
        map<int, int> flags;
        priority_queue<int> maxHeap;

        for (auto x: arr) {
            flags[x]++;
        }

        auto it = flags.begin();
        while (it != flags.end()) {
            maxHeap.push(it->second);
            it++;
        }

        int i = 0;
        int count = 0;
        while (!maxHeap.empty() && count < arr.size() / 2) {
            count += maxHeap.top();
            maxHeap.pop();
            i++;
        }

        return i;
    }

    // https://leetcode.com/problems/sort-characters-by-frequency/
    static bool comparePair(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> flags;
        vector<pair<char, int>> arr;
        string rs;

        for (auto c: s) {
            flags[c]++;
        }

        auto it = flags.begin();
        while (it != flags.end()) {
            arr.push_back(pair<char, int>(it->first, it->second));
            it++;
        }

        sort(arr.begin(), arr.end(), comparePair);

        for (auto x: arr) {
            rs.insert(rs.length(), x.second, x.first);
        }

        return rs;
    }

    // https://leetcode.com/problems/maximum-score-from-removing-stones/
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);


        int rs = 0;
        while (pq.top() != 0) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            if (b == 0) break;

            a--;
            b--;
            rs++;

            pq.push(a);
            pq.push(b);
        }

        return rs;
    }

    // Math
    int maximumScoreC2(int a, int b, int c) {
        int m = max(max(a, b), c);
        if (2 * m > a + b + c) return a + b + c - m;
        return (a + b + c) / 2;
    }

    // https://leetcode.com/problems/word-pattern/
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        vector<string> words;
        map<char, string> charFlags;
        map<string, char> wordFlags;

        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            int p = pattern[i];
            string w = words[i];

            if (charFlags.count(p) > 0 && charFlags[p] != w) return false;
            if (wordFlags.count(w) > 0 && wordFlags[w] != p) return false;

            wordFlags[w] = p;
            charFlags[p] = w;
        }

        return true;
    }

    // https://leetcode.com/problems/check-if-n-and-its-double-exist/
    bool checkIfExist(vector<int> &arr) {
        map<int, int> flags;

        for (auto x: arr) {
            if ((x % 2 == 0 && flags[x / 2] > 0) || (flags[x * 2] > 0)) return true;
            flags[x]++;
        }
        return false;
    }

    // https://leetcode.com/problems/number-of-different-integers-in-a-string/
    int numDifferentIntegers(string word) {
        string numStr = "";
        map<string, int> flags;
        for (auto x: word) {
            if (x >= '0' && x <= '9') {
                numStr += x;
            } else {
                if (!numStr.empty()) {
                    flags[reducePrefixZero(numStr)]++;
                }
                numStr = "";
            }
        }
        if (!numStr.empty()) flags[reducePrefixZero(numStr)]++;

        return flags.size();
    }

    string reducePrefixZero(string numStr) {
        int i = 0;
        while (i < numStr.size() - 1 && numStr[i] == '0') {
            i++;
        }
        return numStr.substr(i, numStr.size() - i);
    }

    // https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
    bool hasGroupsSizeX(vector<int> &deck) {
        map<int, int> flags;
        for (auto x: deck) {
            flags[x]++;
        }

        auto it = flags.begin();
        int rs = it->second;
        while (it != flags.end()) {
            rs = gcd(rs, it->second);
            it++;
        }

        return rs > 1;
    }

    // https://leetcode.com/problems/buddy-strings/
    bool buddyStrings(string s, string goal) {
        vector<int> differIndexes;
        map<char, int> flags;
        bool isContainDup = false;
        int n = s.size();

        if (goal.size() != n) return false;

        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                differIndexes.push_back(i);
                if (differIndexes.size() > 3) return false;
            }

            flags[s[i]]++;
            if (flags[s[i]] > 1) isContainDup = true;
        }

        if (differIndexes.size() == 1) return false;

        if (differIndexes.size() == 2) {
            return s[differIndexes[0]] == goal[differIndexes[1]] && s[differIndexes[1]] == goal[differIndexes[0]];
        }

        return isContainDup;
    }

    // https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> rs;
        map<int, vector<int>> flags;
        int n = groupSizes.size();

        for (int i = 0; i < n; i++) {
            int gSize = groupSizes[i];
            flags[gSize].push_back(i);
            if (flags[gSize].size() == gSize) {
                rs.push_back(flags[gSize]);
                flags[gSize] = vector<int>{};
            }
        }

        return rs;
    }

    // https://leetcode.com/problems/min-cost-climbing-stairs/

    // -> Recursion
    int minCostClimbingStairs(vector<int> &cost) {
        return minCostClimbingStairs(cost, -1);
    }

    int minCostClimbingStairs(vector<int> &cost, int i) {
        int n = cost.size();
        if (i >= n) return 0;

        int min1 = minCostClimbingStairs(cost, i + 1);
        int min2 = minCostClimbingStairs(cost, i + 2);

        if (i < 0) return min(min1, min2);
        return cost[i] + min(min1, min2);
    }

    // -> DP optimization
    int minCostClimbingStairsC2(vector<int> &cost) {
        int i = cost.size() - 1;
        int min1 = cost[i--], min2 = cost[i--];
        int m;
        while (i >= -1) {
            m = cost[i] + min(min1, min2);
            min1 = min2;
            min2 = m;
            i--;
        }
        m = min(min1, min2);

        return m;
    }

    // https://leetcode.com/problems/is-subsequence/
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;

        int i = 0;
        for (auto c: t) {
            if (s[i] == c) {
                i++;
                if (i >= s.size()) return true;
            }
        }

        return false;
    }

    int m = 1e9 + 7;

    int power(int x, int n) {
        long long temp;
        if (n == 0)
            return 1;
        temp = power(x, n / 2) % m;
        if (n % 2 == 0)
            return temp * temp % m;
        else
            return x * temp * temp % m;
    }


    int monkeyMove(int n) {
        int rs = power(2, n) - 2;
        return rs < 0 ? rs + m : rs;
    }


    long long putMarbles(vector<int> &weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        vector<int> candidates;
        for (int i = 0; i < n - 1; i++) {
            candidates.push_back(weights[i] + weights[i + 1]);
        }
        sort(candidates.begin(), candidates.end());
        long long mins = 0, maxs = 0;
        for (int i = 0; i < k - 1; i++) {
            mins += candidates[i];
            maxs += candidates[n - 2 - i];
        }
        return maxs - mins;
    }

};


class Point {
private:
    int x;
    int y;

public:
    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct comparePoints {
    bool operator()(Point *a, Point *b) {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return pow(a->getY(), 2) + pow(a->getY(), 2)
               > pow(b->getX(), 2) + pow(b->getY(), 2);
    }
};

class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<Point *, vector<Point *>, comparePoints> pq;

        for (auto p: points) {
            pq.push(new Point(p[0], p[1]));
        }

        vector<vector<int>> rs;
        while (k-- > 0) {
            Point *temp = pq.top();
            pq.pop();
            rs.push_back(vector<int>{temp->getX(), temp->getY()});
        }

        return rs;
    }
};


class MyQueue {
private:
    vector<int> v1;
    vector<int> v2;

    void checkToMoveV1ToV2() {
        if (v2.empty()) {
            while (!v1.empty()) {
                int top = v1.back();
                v1.pop_back();
                v2.push_back(top);
            }
        }
    }

public:
    MyQueue() {

    }

    void push(int x) {
        v1.push_back(x);
        checkToMoveV1ToV2();
    }

    int pop() {
        int val = -1;
        if (!v2.empty()) {
            val = v2.back();
            v2.pop_back();
            checkToMoveV1ToV2();
        }
        return val;
    }

    int peek() {
        int val = -1;
        if (!v2.empty()) {
            val = v2.back();
        }
        return val;
    }

    bool empty() {
        return v2.empty() && v1.empty();
    }
};


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto x: nums) {
            pq.push(x);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }

};

//int main() {
//    // DATA
//    vector<int> a{10, 15, 20};
//    string s = "a1b01c001";
//
//    // SOLUTION
//    Solution *so = new Solution();
//    so->minCostClimbingStairs(a);
//    return 0;
//}
