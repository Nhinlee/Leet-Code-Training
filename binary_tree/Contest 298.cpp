#include "../stdc++.h"

class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lowerArr(26);
        vector<bool> upperArr(26);

        for (auto c: s) {
            if (c >= 'A' && c <= 'Z') upperArr[c - 'A'] = true;
            if (c >= 'a' && c <= 'z') lowerArr[c - 'a'] = true;
        }

        for (int i = lowerArr.size() - 1; i >= 0; i--) {
            if (lowerArr[i] && upperArr[i]) {
                char c = 'A' + i;
                return string(1, c);
            }
        }

        return "";
    }

    const int mMax = 3001;
    int minSize = mMax;

    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;

        vector<int> kArr{k};
        while (k < num) {
            k += 10;
            kArr.push_back(k);
        }

        dfs(kArr, num, 0);

        return minSize == mMax ? -1 : minSize;
    }

    void dfs(vector<int> &kArr, int num, int curr) {
        for (auto x: kArr) {
            if (num - x < 0) break;
            dfs(kArr, num - x, curr + 1);
            if (num - x == 0) {
                minSize = min(minSize, curr) + 1;
            }
        }
    }
};
