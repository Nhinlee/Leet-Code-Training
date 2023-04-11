#include "../stdc++.h"

class Solution {
public:
    string removeStars(string s) {
        string rs = "";
        int countStar = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                countStar++;
            } else {
                if (countStar > 0) {
                    countStar--;
                } else {
                    rs.push_back(s[i]);
                }
            }
        }

        std::reverse(rs.begin(), rs.end());
        return rs;
    }
};