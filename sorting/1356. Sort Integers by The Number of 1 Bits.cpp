#include "../stdc++.h"

class Solution {
public:
    static int countNumber1Of(int a) {
        int sum1 = 0;
        while (a > 0) {
            sum1 += a % 2;
            a = a / 2;
        }
        return sum1;
    }

    static int compare(const int &a, const int &b) {
        int c1 = countNumber1Of(a);
        int c2 = countNumber1Of(b);
        if (c1 != c2) return c1 < c2;
        return a < b;
    }

    vector<int> sortByBits(vector<int> &arr) {
        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};

//int main() {
//    Solution *s = new Solution();
//    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//    s->sortByBits(arr);
//}