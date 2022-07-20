#include "../stdc++.h"

class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        int count = 0;
        // Save all word s in the map<char, vector<int>>
        map<char, vector<int>> flags;
        for (int i = 0; i < s.size(); i++) {
            flags[s[i]].push_back(i);
        }

        // Check isSubsequence algorithm
        vector<int> charIndex(26);
        for (auto word: words) {
            int currIndex = -1;
            bool isSubsequence = true;

            for (auto c: word) {
                int j = charIndex[c - 'a'];
                while (j < flags[c].size() && flags[c][j] <= currIndex) j++;

                if (j >= flags[c].size()) {
                    isSubsequence = false;
                    break;
                }

                currIndex = flags[c][j];
                charIndex[c - 'a'] = j;
            }

            if (isSubsequence)count++;
            charIndex.assign(26, 0);
        }

        return count;
    }
};