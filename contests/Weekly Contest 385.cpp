#include "../stdc++.h"

typedef pair<vector<int>, int> scores;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string> &words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixSuffixPairs(words[i], words[j])) count++;
            }
        }

        return count;
    }

    bool isPrefixSuffixPairs(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }
        for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0; i--, j--) {
            if (s1[i] != s2[j]) return false;
        }

        return true;
    }

    // https://leetcode.com/contest/weekly-contest-385/problems/find-the-length-of-the-longest-common-prefix/
    // Bruce forth
    int longestCommonPrefixC1(vector<int> &arr1, vector<int> &arr2) {
        int longest = 0;
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                longest = max(longest, countCommonPrefix(arr1[i], arr2[j]));
            }
        }

        return longest;
    }

    int countCommonPrefix(int a, int b) {
        string as, bs;
        as = to_string(a);
        bs = to_string(b);

        int i = 0;
        for (; i < as.size() || i < bs.size(); i++) {
            if (as[i] != bs[i]) break;
        }

        return i;
    }

    // C2: Hash map
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        int longest = 0;

        map<string, bool> prefixMap;
        for (int i = 0; i < arr1.size(); i++) {
            string str = to_string(arr1[i]);
            string prefixStr;
            for (int j = 0; j < str.size(); j++) {
                prefixStr += str[j];
                prefixMap[prefixStr] = true;
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            string str = to_string(arr2[i]);
            string prefixStr;
            for (int j = 0; j < str.size(); j++) {
                prefixStr += str[j];
                if (prefixMap[prefixStr]) {
                    int n = prefixStr.size();
                    longest = max(longest, n);
                }
            }
        }

        return longest;
    }

    // https://leetcode.com/contest/weekly-contest-385/problems/count-prefix-and-suffix-pairs-ii/
    
};

//int main() {
//    Solution *s = new Solution();
//    vector<int> a = vector<int>{1, 2, 1, 2, 1, 3, 3};
//    cout << s->minCost(a, 2);
//}