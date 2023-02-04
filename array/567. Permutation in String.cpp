#include "../stdc++.h"

class Solution {
public:
    // Time: O(n^2), Space: O(n)
    bool checkInclusion(string s1, string s2) {
        map<char, int> s1Map;
        int n1 = s1.size(), n2 = s2.size();
        for (auto c: s1) {
            s1Map[c]++;
        }

        for (int i = 0; i < n2 - n1 + 1; i++) {
            int j = 0;

            if (s1Map[s2[i]] > 0) {
                auto s1MapCpy = s1Map;

                while (s1MapCpy[s2[i + j]] > 0 && j < n1) {
                    s1MapCpy[s2[i + j]]--;
                    j++;
                }

                if (j == n1) return true;
            }
        }

        return false;
    }

    // Time: O(l1 + 26*l2), Space: O(n)
    bool checkInclusionC2(string s1, string s2) {
        vector<int> s1Map(26), s2Map(26);
        int n = s1.size();

        for (auto c: s1) {
            s1Map[c - 'a']++;
        }

        for (int i = 0; i < s2.size(); i++) {
            char c = s2[i];
            s2Map[c - 'a']++;

            if (isMatches(s1Map, s2Map)) return true;

            if (i >= n - 1) {
                s2Map[s2[i - n + 1] - 'a']--;
            }
        }

        return isMatches(s1Map, s2Map);
    }

    bool isMatches(vector<int> &s1Map, vector<int> &s2Map) {
        for (int i = 0; i < 26; i++) {
            if (s1Map[i] != s2Map[i]) return false;
        }

        return true;
    }

};

int main() {
    Solution *s = new Solution();
    cout << s->checkInclusion("ab", "ab");
}