#include "../stdc++.h"

class Solution {
public:
    // C1: Sorting O(n.log(n)), memory O(1)
    int maxIceCream(vector<int> &costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int c = 0;
        for (auto co: costs) {
            coins -= co;
            if (coins >= 0) {
                c++;
            } else {
                return c;
            }
        }

        return c;
    }

    // C2: Hash - O(n), memory O(n)
    int maxIceCreamC2(vector<int> &costs, int coins) {
        int c = 0, maxCost = -1;
        for (auto cost: costs) {
            maxCost = max(maxCost, cost);
        }

        vector<int> flags(maxCost + 1, 0);
        for (auto cost: costs) {
            flags[cost]++;
        }

        for (int i = 1; i <= maxCost; i++) {
            while (flags[i]-- > 0) {
                coins -= i;
                if (coins >= 0) {
                    c++;
                } else {
                    return c;
                }
            }
        }

        return c;
    }
};