#include "../stdc++.h"

class Solution {
public:
    int isWinner(vector<int> &player1, vector<int> &player2) {
        int sum1 = 0, sum2 = 0;

        int dup = 1, c = 0;
        for (auto x: player1) {
            c++;
            if (c > 2) sum1 += x; else sum1 += x * dup;
            if (x == 10) {
                dup = 2;
                c = 0;
            }
        }

        dup = 1, c = 0;
        for (auto x: player2) {
            c++;
            if (c > 2) sum2 += x; else sum2 += x * dup;
            if (x == 10) {
                dup = 2;
                c = 0;
            }
        }

        if (sum1 == sum2) return 0;
        return sum1 > sum2 ? 1 : 2;
    }

    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> cRow(n), cCol(m);
        map<int, pair<int, int>> posMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                posMap[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            auto pos = posMap[arr[i]];
            cRow[pos.first]++;
            cCol[pos.second]++;

            if (cRow[pos.first] == m || cCol[pos.second] == n) return i;
        }

        return arr.size() - 1;
    }
};

//int main() {
//    vector<int> nums = vector<int>{10, 5, 10, 30, 70, 4, 2, 6, 8, 4};
//    vector<int> d = vector<int>{7, 4};
//    string t = "aaaaab";
//    Solution *s = new Solution();
//
//    return 0;
//}