#include "../stdc++.h"

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days) {

        // Binary search the result here:
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int l = sum / days;
        int r = sum;

        while (l < r) {
            int mid = (l + r) / 2;
            if (positive(weights, days, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }


    // Sorted weights
    bool positive(vector<int> &weights, int days, int capacity) {
        vector<int> packs(days, capacity);

        int i = 0;
        int j = 0;
        while (i <= weights.size() - 1) {
            while (j < packs.size() && packs[j] < weights[i]) j++;
            if (j >= packs.size()) return false;

            packs[j] -= weights[i];
            i++;
        }

        return true;
    }
};

