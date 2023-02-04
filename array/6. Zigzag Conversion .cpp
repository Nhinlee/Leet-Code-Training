#include "../stdc++.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int index = 0, d = 1;
        vector<string> rows(numRows);

        for (auto c: s) {
            rows[index] += c;
            if (index + d >= numRows || index + d < 0) {
                d *= -1;
            }

            index += d;
        }

        string rs = "";
        for (auto row: rows) {
            rs += row;
        }

        return rs;
    }

    string convertC2(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string answer;
        int n = s.size();
        int charsInSection = 2 * (numRows - 1);

        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while (index < n) {
                answer += s[index];

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;

                    if (secondIndex < n) {
                        answer += s[secondIndex];
                    }
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }

        return answer;
    }
};