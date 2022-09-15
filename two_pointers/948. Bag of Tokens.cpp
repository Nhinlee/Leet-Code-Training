#include "../stdc++.h"

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int n = tokens.size();
        int i = 0, j = n - 1, score = 0;
        while (i <= j && i <= n - 1 && power >= tokens[i]) {
            score++;
            power -= tokens[i];

            while (j > i + 1 && power < tokens[i + 1] && score > 0) {
                power += tokens[j];
                score--;
                j--;
            }

            i++;
        }

        return score;
    }
};