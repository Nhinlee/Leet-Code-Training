#include "../stdc++.h"

class Solution {
public:
    // C1
    bool detectCapitalUse(string word) {
        if (word.length() == 1) return true;

        bool isAllCapitals = true, isAllLows = true;

        for (int i = 1; i < word.length(); i++) {
            if (isCapital(word[i])) {
                isAllLows = false;
            } else {
                isAllCapitals = false;
            }
        }

        if (isCapital(word[0])) {
            return isAllCapitals || isAllLows;
        } else {
            return isAllLows;
        }
    }

    // C2: Memory optimization
    bool detectCapitalUseC2(string word) {
        if (word.length() == 1) return true;

        int capitalCount = 0;

        for (int i = 1; i < word.length(); i++) {
            if (isCapital(word[i])) {
                capitalCount++;
            }
        }

        if (isCapital(word[0])) {
            return capitalCount == word.length() - 1 || capitalCount == 0;
        } else {
            return capitalCount == 0;
        }
    }


    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
};