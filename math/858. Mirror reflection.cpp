#include "../stdc++.h"

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int dx = -1, dy = 1, delta = 0;

        do {
            int div = (p - delta) / q;
            delta = q - (p - delta) % q;

            // switch direction
            if (div % 2 == 0) dx *= -1;
            dy *= -1;

        } while (delta != q);

        // switch direction again for get rs
        dx *= -1;

        if (dy == -1) {
            return dx == -1 ? 2 : 1;
        }
        return 0;
    }
};