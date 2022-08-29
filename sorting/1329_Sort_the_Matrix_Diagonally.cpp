#include "../stdc++.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int row = mat.size(), col = mat[0].size();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < row; i++) {
            int k = i, j = 0;
            while (k < row && j < col) {
                minHeap.push(mat[k][j]);
                k++;
                j++;
            }
            //
            k = i;
            j = 0;
            while (k < row && j < col) {
                mat[k][j] = minHeap.top();
                minHeap.pop();
                k++;
                j++;
            }
        }

        for (int i = 1; i < col; i++) {
            int k = i, j = 0;
            while (k < col && j < row) {
                minHeap.push(mat[j][k]);
                k++;
                j++;
            }
            //
            k = i;
            j = 0;
            while (k < col && j < row) {
                mat[j][k] = minHeap.top();
                minHeap.pop();
                k++;
                j++;
            }
        }

        return mat;
    }
};