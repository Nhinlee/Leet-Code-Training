#include "../stdc++.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return vector<int>{};

        vector<int> sMap(26), pMap(26), rs;
        int pN = p.size(), sN = s.size();

        for (int i = 0; i < p.size(); i++) {
            pMap[p[i] - 'a']++;
            sMap[s[i] - 'a']++;
        }

        for (int i = pN; i < sN; i++) {
            if (isMatches(sMap, pMap)) rs.push_back(i - pN);

            sMap[s[i] - 'a']++;
            sMap[s[i - pN] - 'a']--;
        }

        if (isMatches(sMap, pMap)) rs.push_back(sN - pN);

        return rs;
    }

    bool isMatches(vector<int> &map1, vector<int> &map2) {
        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) return false;
        }

        return true;
    }
};