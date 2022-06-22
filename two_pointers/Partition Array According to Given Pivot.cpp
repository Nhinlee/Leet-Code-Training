#include "../stdc++.h"

class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        int n = nums.size();
        vector<int> rs(n, pivot);

        int i = 0, j = n - 1;
        for (int k = 0, l = n - 1; k < nums.size() && l >= 0; k++, l--) {
            if (nums[k] < pivot) rs[i++] = nums[k];
            if (nums[l] > pivot) rs[j--] = nums[l];
        }

        return rs;
    }
};