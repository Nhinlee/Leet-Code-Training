#include "../stdc++.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));

        int left = 0, right = n-1, top = 0, bottom = n-1, k = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result[top][i] = k;
                k++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result[i][right] = k;
                k++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = k;
                    k++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = k;
                    k++;
                }
                left++;
            }
        }

        return result;
    }
};
