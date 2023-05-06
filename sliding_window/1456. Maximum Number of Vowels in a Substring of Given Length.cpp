#include "../stdc++.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, i = 0, j = 0, rs = 0;
        for (i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }
        rs = count;

        while (i < s.size()) {
            if (isVowel(s[i])) count++;
            if (!isVowel(s[j])) count--;

            rs = max(rs, count);
            i++;
            j++;
        }

        return rs;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};