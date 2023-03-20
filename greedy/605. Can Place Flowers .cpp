#include "../stdc++.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int rest = 0, count0 = 0;

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for (auto f: flowerbed) {
            if (f == 0) count0++; else count0 = 0;
            if (count0 == 3) {
                rest++;
                count0 = 1;
            }
        }

        return n <= rest;
    }
};