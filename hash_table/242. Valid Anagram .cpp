#include "../stdc++.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> chars(26, 0);

        for (auto c: s) {
            chars[c - 'a']++;
        }
        for (auto c: t) {
            chars[c - 'a']--;
            if (chars[c - 'a'] < 0) return false;
        }

        return true;
    }
};