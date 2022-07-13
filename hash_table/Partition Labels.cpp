#include "../stdc++.h"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> lastIndexFlags;
        vector<int> rs;
        for (int i = 0; i < s.size(); i++) {
            lastIndexFlags[s[i]] = i;
        }

        int start = 0, i = 0;
        int maxCurrentIndex = lastIndexFlags[s[0]];
        for (i = 0; i < s.size(); i++) {
            if (i <= maxCurrentIndex) {
                if (lastIndexFlags[s[i]] > maxCurrentIndex) {
                    maxCurrentIndex = lastIndexFlags[s[i]];
                }
            } else {
                rs.push_back(i - start);
                start = i;
                maxCurrentIndex = lastIndexFlags[s[i]];
            }
        }
        rs.push_back(i - start);

        return rs;
    }
};