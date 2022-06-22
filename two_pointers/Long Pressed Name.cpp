#include "../stdc++.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.length() < name.length()) return false;

        int j = 0;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] == typed[j]) {
                while (i < name.length() - 1 && name[i] == name[i + 1]) {
                    i++;
                    j++;
                    if (name[i] != typed[j]) return false;
                }
                while (j < typed.length() - 1 && typed[j] == typed[j + 1]) j++;
            } else {
                return false;
            }

            j++;
        }

        if (j < typed.length() - 1) return false;
        return true;
    }

    bool isLongPressedNameC2(string name, string typed) {
        int i = 0, n = typed.length();

        if (name[0] != typed[0]) return false;

        for (int j = 0; j < n; j++) {
            if (typed[j] == name[i]) {
                i++;
                continue;
            }

            if (i > 0 && typed[j] != name[i - 1]) return false;
        }

        return i == name.length();
    }
};

