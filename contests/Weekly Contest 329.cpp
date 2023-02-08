#include "../stdc++.h"

typedef pair<vector<int>, int> scores;

class Solution {
public:
    // https://leetcode.com/contest/weekly-contest-329/problems/alternating-digit-sum/
    int alternateDigitSum(int n) {
        int sign = 1;
        int l = to_string(n).size();
        if (l == 1) return n;
        if (l % 2 == 0) sign = -1;

        int sum = 0;
        while (n > 0) {
            sum += n % 10 * sign;
            sign *= -1;
            n /= 10;
        }

        return sum;
    }


    // https://leetcode.com/contest/weekly-contest-329/problems/sort-the-students-by-their-kth-score/
    struct Compare {
        int k;

        const bool operator()(vector<int> &a, vector<int> &b) {
            return a[k] > b[k];
        }
    };

    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
        auto compare = Compare();
        compare.k = k;
        sort(score.begin(), score.end(), compare);

        return score;
    }

    // https://leetcode.com/contest/weekly-contest-329/problems/apply-bitwise-operations-to-make-strings-equal/
    // Explain:
    // 00 -> 00, 01 -> 11, 10 -> 11, 11 -> 10
    // We can easily see if exist 1 in string, we can turn it into what ever string we want (except ZERO STRING)

    bool makeStringsEqual(string s, string target) {
        if (s == target) return true;
        if (isAllZero(target) || isAllZero(s)) return false;

        return true;
    }

    bool isAllZero(string s) {
        for (auto c: s) {
            if (c != '0') return false;
        }

        return true;
    }

    // https://leetcode.com/contest/weekly-contest-329/problems/minimum-cost-to-split-an-array/
    int minCost(vector<int> &nums, int k) {
        int minn = trimmed(nums, 0) + k;
        vector<int> numsCp = nums;
        std::reverse(numsCp.begin(), numsCp.end());
        for (int i = 1; i * k < nums.size(); i++) {
            minn = min(i * k + calcCost(nums, i), minn);
            minn = min(i * k + calcCost(numsCp, i), minn);
        }

        return minn;
    }

    int calcCost(vector<int> &nums, int numSubs) {
        int i = 0;
        while (numSubs > 1) {
            map<int, int> flags;
            while (i < nums.size()) {
                if (flags[nums[i]] > 0) {
                    numSubs--;
                    break;
                }
                flags[nums[i]]++;
                i++;
            }
        }

        if (numSubs > 1 || i == nums.size()) return 0;

        return trimmed(nums, i);
    }

    int trimmed(vector<int> &nums, int i) {
        map<int, int> flags;
        while (i < nums.size()) {
            flags[nums[i]]++;
            i++;
        }

        int length = 0;
        for (auto it: flags) {
            if (it.second > 1) {
                length += it.second;
            }
        }

        return length;
    }

    int minCostC2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp.back() = 0;
        for (int i = n-1; i >= 0; --i) {
            int sum = 0;
            vector<int> freq(n);
            for (int j = i; j < n; ++j) {
                int cnt = ++freq[nums[j]];
                if (cnt == 2) sum += 2;
                else if (cnt > 2) ++sum;
                dp[i] = min(dp[i], k + sum + dp[j+1]);
            }
        }
        return dp[0];
    }
};

//int main() {
//    Solution *s = new Solution();
//    vector<int> a = vector<int>{1, 2, 1, 2, 1, 3, 3};
//    cout << s->minCost(a, 2);
//}