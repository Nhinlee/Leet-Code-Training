#include "../stdc++.h"

class Solution {
public:
    string trimRightMostXDigit(string num, int x) {
        if (x >= num.size()) return num;
        return num.substr(num.size() - x, x);
    }

    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        vector<int> ans;

        for (auto q: queries) {
            int x = q[1];
            int k = q[0];
            vector<pair<string, int>> trimmedNums;

            for (int i = 0; i < nums.size(); i++) {
                string trimNum = trimRightMostXDigit(nums[i], x);
                trimmedNums.push_back(pair<string, int>{trimNum, i});
            }
            sort(trimmedNums.begin(), trimmedNums.end());

            ans.push_back(trimmedNums[k - 1].second);

        }
        return ans;
    }
};
