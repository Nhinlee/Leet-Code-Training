#include "../stdc++.h"

// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxH = 0, maxV = 0;
        for (int i = 0; i < horizontalCuts.size() - 1; i++) {
            maxH = max((long long)horizontalCuts[i + 1] - horizontalCuts[i], maxH);
        }

        for (int i = 0; i < verticalCuts.size() - 1; i++) {
            maxV = max((long long)verticalCuts[i + 1] - verticalCuts[i], maxV);
        }

        return (maxH * maxV) % 1000000007;
    }
};