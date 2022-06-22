#include "../stdc++.h"

class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        vector<vector<int>> rs;
        int y = 1000;
        for (int x = 1; x < 1000; x++) {
            while (y > 1 && customfunction.f(x, y) > z) y--;
            if (customfunction.f(x, y) == z) {
                rs.push_back(vector<int>{x, y});
            }
        }

        return rs;
    }
};