#include "../stdc++.h"

class Solution {
public:
    bool isAlienSorted(vector <string> &words, string order) {
        auto orderMap = vector<int>(26);
        for (int i = 0; i < order.length(); i++){
            orderMap[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {

            for (int j = 0; j < words[i].length(); j++) {
                if (j >= words[i + 1].length()) return false;

                if (words[i][j] != words[i + 1][j]) {
                    int currentWordChar = words[i][j] - 'a';
                    int nextWordChar = words[i + 1][j] - 'a';
                    if (orderMap[currentWordChar] > orderMap[nextWordChar]) return false;
                    else break;
                }
            }
        }

        return true;
    }
};