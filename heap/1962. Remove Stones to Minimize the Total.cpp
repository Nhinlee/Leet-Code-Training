#include "../stdc++.h"

typedef pair<int, int> pp;

struct Compare {
    bool operator()(const pp &a, const pp &b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    // C1: Using max heap with custom pair
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<pp, vector<pp>, Compare> q;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            q.push({piles[i], i});
        }

        while (k-- > 0) {
            auto maxx = q.top();
            q.pop();

            //
            int value = maxx.first - floor(maxx.first / 2);
            int index = maxx.second;
            piles[index] = value;
            q.push({value, index});
        }

        int sum = 0;
        for (auto x: piles) {
            sum += x;
        }
        return sum;
    }

    // C2: Using max heap with int only (reduce memory cost)
    int minStoneSumC2(vector<int> &piles, int k) {
        priority_queue<int> pq;
        int n = piles.size(), sum = 0;
        for (auto x: piles) {
            sum += x;
            pq.push(x);
        }

        while (k-- > 0) {
            auto maxx = pq.top();
            pq.pop();

            //
            int delta = floor(maxx / 2);
            sum -= delta;
            pq.push(maxx - delta);
        }

        return sum;
    }
};

//int main() {
//    Solution *s = new Solution();
//    auto a = vector<int>{5, 4, 9};
//    cout << s->minStoneSum(a, 2);
//
//    return 0;
//}