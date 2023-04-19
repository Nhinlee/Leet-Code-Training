#include "../stdc++.h"

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
        int maxx = 0, maxxIndex = 0, n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < m; j++) {
                c += mat[i][j];
            }
            if (c > maxx) {
                maxx = c;
                maxxIndex = i;
            }
        }

        return vector<int>{maxxIndex, maxx};
    }

    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        int maxx = -1;
        vector<int> maxDScores;
        for (auto d: divisors) {
            int c = 0;
            for (auto n: nums) {
                if (n % d == 0) c++;
            }
            if (c > maxx) {
                maxDScores = vector<int>();
                maxx = c;
                maxDScores.push_back(d);
            } else if (c == maxx) {
                maxDScores.push_back(d);
            }

        }

        sort(maxDScores.begin(), maxDScores.end());

        return maxDScores[0];
    }

    int addMinimum(string word) {
        int n = word.size(), c = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 2) {
                auto substr = word.substr(i, 3);
                if (substr == "abc") {
                    i += 2;
                    continue;
                }
            }

            if (i < n - 1) {
                auto substr = word.substr(i, 2);
                if (substr == "ab" || substr == "ac" || substr == "bc") {
                    i += 1;
                    c++;
                    continue;
                }
            }

            c += 2;
        }

        return c;
    }
};

int main() {
    vector<int> nums = vector<int>{39, 70, 33};
    vector<int> d = vector<int>{7, 4};
    string t = "aaaaab";
    Solution *s = new Solution();
    cout << s->addMinimum(t);
    return 0;
}