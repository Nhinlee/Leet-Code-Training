#include "../stdc++.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> rs;
        for (auto word: words) {
            if (matchingPattern(word, pattern)) rs.push_back(word);
        }

        return rs;
    }

    bool matchingPattern(string word, string pattern) {
        map<char, char> wordFlags;
        map<char, char> patternFlags;
        for (int i = 0; i < word.size(); i++) {
            if (wordFlags[word[i]] > 0 && wordFlags[word[i]] != pattern[i]) return false;
            if (patternFlags[pattern[i]] > 0 && patternFlags[pattern[i]] != word[i]) return false;

            patternFlags[pattern[i]] = word[i];
            wordFlags[word[i]] = pattern[i];
        }
        return true;
    }
};