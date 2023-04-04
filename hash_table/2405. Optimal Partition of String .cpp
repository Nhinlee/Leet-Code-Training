#include "../stdc++.h"

class Solution {
public:
    int partitionString(string s) {
        vector<int> flags(26);
        int count = 1;

        for (auto c: s) {
            flags[c - 'a']++;
            if (flags[c - 'a'] > 1) {
                count++;
                flags = vector<int>(26);
                flags[c - 'a']++;
            }
        }

        return count;
    }
};