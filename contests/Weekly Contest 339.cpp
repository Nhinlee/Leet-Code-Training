#include "../stdc++.h"

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxLength = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                int j = i + 1;
                int l = 1, c = 1;
                while (j < n && !(s[j] == '0' && s[j - 1] == '1')) {
                    if (s[j] == '0') {
                        c++;
                    }
                    j++;
                    l++;
                }

                maxLength = max(maxLength, min((l - c) * 2, c * 2));
                i = j - 1;
            }
        }
        return maxLength;
    }

    vector<vector<int>> findMatrix(vector<int> &nums) {
        int c = 0, n = nums.size();
        vector<int> indexVis(n + 1);
        vector<vector<int>> rs;

        while (c < n) {
            vector<bool> vis(n + 1);
            vector<int> row;
            for (int i = 0; i < n; i++) {
                if (!indexVis[i] && !vis[nums[i]]) {
                    indexVis[i] = true;
                    vis[nums[i]] = true;
                    c++;
                    row.push_back(nums[i]);
                }
            }

            rs.push_back(row);
        }

        return rs;
    }

    static bool compare(pp a, pp b) {
        // sort in descending order
        return a.first < b.first;
    }

    // IN PROGRESS
    int miceAndCheese(vector<int> &r1, vector<int> &r2, int k) {
        vector<pp> r;
        int n = r1.size();
        for (int i = 0; i < n; i++) {
            r.push_back({r1[i], i});
            r.push_back({r2[i], i});
        }

        sort(r.begin(), r.end(), compare);

        k *= 2;
        int i = r.size() - 1, sum = 0;
        vector<bool> eatens(n);
        while (k >= 0 && i >= (r.size() - 1) / 2) {
            int value = r[i].first;
            int index = r[i].second;
            if (!eatens[index]) {
                sum += value;
                eatens[index] = true;
                k--;
            }

            i--;
        }

        return sum;
    }
};

//int main() {
//    Solution *s = new Solution();
//
//    cout << s->findTheLongestBalancedSubstring("01000111");
//}