#include "../stdc++.h"

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }

        // Not have available circle route
        if (sum < 0) return -1;

        // Loop to check circle route
        sum = 0;
        int st = 0, i = 0, c = 0;
        while (c < n) {
            sum += gas[i];
            if (sum < 0) {
                c = 0;
                st = i + 1;
                sum = 0;
            } else {
                c++;
            }

            i++;
            if (i >= n) {
                i = 0;
            }
        }

        return st;
    }
};