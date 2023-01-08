#include "../stdc++.h"

typedef pair<int, int> point;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() <= 1) return 1;

        int a, b, c, n = points.size();
        vector<int> x, y;
        map<string, set<point>> flags;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                x = points[i];
                y = points[j];

                a = x[0] - y[0];
                b = x[1] - y[1];
                c = b * x[0] - a * x[1];

                // Format 3 number
                if (a < 0) {
                    a = -a;
                    b = -b;
                    c = -c;
                }

                // hash line: -bx + ay - c = 0
                auto h = hash(-b, a, c);
                flags[h].insert({x[0], x[1]});
                flags[h].insert({y[0], y[1]});
            }
        }

        int rs = 0;
        for (auto f: flags) {
            int s = f.second.size();
            rs = max(rs, s);
        }

        return rs;
    }

    string hash(int a, int b, int c) {
        int g = gcd(gcd(a, b), gcd(b, c));
        return to_string(a / g) + to_string(b / g) + to_string(c / g);
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> t = vector<vector<int>>{{1, 1},
                                                {2, 2},
                                                {3, 3},
    };
    cout << s->maxPoints(t);
}