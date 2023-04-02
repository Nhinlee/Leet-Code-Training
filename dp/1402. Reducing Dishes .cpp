#include "../stdc++.h"

class Solution {
public:
    int maxSatisfaction(vector<int> &s) {
        int maxx = 0, sum = 0, n = s.size();

        sort(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            int t = s[i] * (i + 1);
            maxx += t;
            sum += s[i];
        }

        for (int i = 0; i < n; i++) {
            sum -= s[i];
            if (s[i] < 0) {
                maxx = max(maxx, maxx - s[i] - sum);
            }
        }

        return maxx;
    }
};

//int main() {
//    Solution *s = new Solution();
//    auto a = vector<int>{2, -2, -3, 1};
//    cout << s->maxSatisfaction(a);
//    return 0;
//}