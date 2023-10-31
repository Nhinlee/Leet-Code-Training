#include "../stdc++.h"

class Solution {
public:
    vector<int> findArray(vector<int> &a) {
        vector<int> rs(a.size());
        rs[0] = a[0];
        for (int i = 1; i < a.size(); i++) {
            rs[i] = a[i] ^ a[i - 1];
        }

        return rs;
    }
};