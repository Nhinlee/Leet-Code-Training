#include "../stdc++.h"

class Solution {
public:
    // C1: recursive
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

class Solution2 {
public:
    // C2: dp
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        int t1 = 0, t2 = 1, t3 = 1, temp;
        while (n-- > 2) {
            temp = t3;
            t3 = t1+ t2 + t3;
            t1 = t2;
            t2 = temp;
        }

        return t3;
    }
};