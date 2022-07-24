#include "../stdc++.h"

class Solution {
public:
    // C1: Binary search way
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // Search
        int i = 0, j = 0;
        while (i < m && j < n && matrix[i][j] < target) {
            i++;
            j++;
        }
        if (i < m && j < n && matrix[i][j] == target) return true;

        // Binary search
        while (i < m) {
            if (matrix[i][0] > target) break;
            if (bsOnRow(matrix[i], target)) return true;
            i++;
        }

        while (j < n) {
            if (matrix[0][j] > target) break;
            if (bsOnColumn(matrix, j, target)) return true;
            j++;
        }

        return false;
    }

    bool bsOnRow(vector<int> arr, int target) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] > target) r = mid - 1; else l = mid + 1;
        }
        return false;
    }

    bool bsOnColumn(vector<vector<int>> &matrix, int column, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid][column] == target) return true;
            if (matrix[mid][column] > target) r = mid - 1; else l = mid + 1;
        }
        return false;
    }


    // C2: O(m+n) way
    bool searchMatrixC2(vector<vector<int>> &matrix, int target) {
        int col = matrix[0].size() - 1, row = 0;

        while (col >= 0 && row <= matrix.size() - 1) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};