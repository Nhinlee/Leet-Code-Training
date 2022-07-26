#include "../stdc++.h"

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        map<string, int> flags;
        vector<string> ans;

        for (auto c: cpdomains) {
            auto cp = getSplitCountAndDomain(c);
            countAndSaveToSubDomain(cp.second, flags, cp.first);
        }

        for (auto it: flags) {
            ans.push_back(to_string(it.second) + " " + it.first);
        }

        return ans;
    }

    pair<int, string> getSplitCountAndDomain(string s) {
        stringstream ss(s);
        string word;

        ss >> word;
        int visitCount = stoi(word);

        ss >> word;
        return pair<int, string>{visitCount, word};
    }

    void countAndSaveToSubDomain(string s, map<string, int> &flags, int count) {
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == '.') {
                flags[s.substr(i + 1)] += count;
            }
        }
        flags[s] += count;
    }
};