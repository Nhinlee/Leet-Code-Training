#include "../stdc++.h"

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < s.size() && s[j] < g[i]) j++;
            if (j >= s.size()) break;

            j++;
            count++;
        }

        return count;
    }

    int findContentChildrenC2(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;

        for (int i = 0; i < s.size() & j < g.size(); i++) {
            if (g[j] <= s[i]) j++;
        }

        return j;
    }
};