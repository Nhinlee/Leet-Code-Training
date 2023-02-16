#include "../stdc++.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &num, int k) {
        int d = 0;

        for (int i = num.size() - 1; i >= 0; i--) {
            num[i] += k % 10 + d;
            if (num[i] >= 10) {
                d = 1;
                num[i] %= 10;
            } else {
                d = 0;
            }
            k /= 10;
        }

        while (k > 0) {
            int sum = k % 10 + d;
            if (sum >= 10) {
                d = 1;
                sum %= 10;
            } else {
                d = 0;
            }
            num.insert(num.begin(), sum);
            k /= 10;
        }

        if (d > 0 && k == 0) {
            num.insert(num.begin(), d);
        }


        return num;
    }

    vector<int> addToArrayFormC2(vector<int> &num, int k) {
        int n = num.size();
        int cur = k;
        vector<int> ans;

        int i = n;
        while (--i >= 0 || cur > 0) {
            if (i >= 0)
                cur += num[i];
            ans.push_back(cur % 10);
            cur /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};