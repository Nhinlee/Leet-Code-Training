#include "../stdc++.h"

class Solution {
public:
    int minDeletionSize(vector<string> &arr) {
        int n = arr[0].length(), i = 0, c = 0;
        while (i < n) {
            for (int j = 0; j < arr.size() - 1; j++) {
                if (arr[j][i] > arr[j + 1][i]) {
                    c++;
                    break;
                }
            }
            i++;
        }

        return c;
    }
};