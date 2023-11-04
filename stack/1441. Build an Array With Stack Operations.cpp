#include "../stdc++.h"

class Solution {
public:
    vector<string> buildArray(vector<int> &target, int n) {
        int i = 0, maxx = target[target.size() - 1];
        vector<string> rs;

        for (int j = 1; j <= maxx; j++) {
            if (j == target[i]) {
                i++;
                rs.push_back("Push");
            } else {
                rs.push_back("Push");
                rs.push_back("Pop");
            }
        }

        return rs;
    }
};