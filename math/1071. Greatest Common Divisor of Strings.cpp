#include "../stdc++.h"

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.size(), str2.size());

        if (!isCanDivide(str1, g) || !isCanDivide(str2, g)) return "";

        string rs = "";
        for (int i = 0; i < g; i++) {
            rs += str1[i];
            if (str1[i] != str2[i]) return "";
        }

        return rs;
    }

    bool isCanDivide(string s, int g) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[i % g]) return false;
        }
        return true;
    }

    string gcdOfStringsC2(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->gcdOfStrings("ABCABC", "ABC");
}