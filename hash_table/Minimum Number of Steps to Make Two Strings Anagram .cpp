#include "../stdc++.h"

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> charFlags(26,0);
        int count = 0;
        for (auto x: s) {
            charFlags[x - 'a']++;
        }
        for (auto x: t) {
            if (charFlags[x - 'a'] > 0) {
                charFlags[x - 'a']--;
            } else {
                count++;
            }
        }

        return count;
    }
};