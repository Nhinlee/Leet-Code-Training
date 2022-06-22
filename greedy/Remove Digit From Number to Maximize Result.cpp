#include "../stdc++.h"

// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size(), lastIndex = 0, i = 0;

        for (i = 0; i < n - 1; i++) {
            if (number[i] == digit) {
                if (number[i + 1] > number[i]) {
                    number.erase(i, 1);
                    return number;
                }
                lastIndex = i;
            }
        }

        if (number[i] == digit) lastIndex = i;
        number.erase(lastIndex, 1);
        return number;
    }
};