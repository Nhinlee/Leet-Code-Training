#include "../stdc++.h"

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;
        while (k--) {
            next_permutation(num.begin(), num.end());
        }

        return minSteps(original, num);
    }

    int minSteps(string original, string num) {
        int i = 0, j = 0, n = original.size(), rs = 0;
        while (i < n) {
            j = i;
            while (original[i] != num[j]) j++;

            while (i < j) {
                swap(num[j], num[j - 1]);
                j--;
                rs++;
            }

            i++;
        }

        return rs;
    }

};