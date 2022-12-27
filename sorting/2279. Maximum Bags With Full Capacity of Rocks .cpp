#include "../stdc++.h"

class Solution {
public:
    // C1: Quick sort
    // Time complexity: sort = nlog(n)
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = capacity.size();
        for (int i = 0; i < n; i++) {
            capacity[i] -= rocks[i];
        }

        sort(capacity.begin(), capacity.end());

        int i = 0, fullBags = 0;
        while (additionalRocks > 0 && i < n) {
            additionalRocks -= capacity[i];
            if (additionalRocks >= 0) {
                fullBags++;
            }
            i++;
        }

        return fullBags;
    }

    // C2: Using Heap:
    // Time complexity: insert + remove = nlog(n) + nlog(n)
    int maximumBagsC2(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = capacity.size();
        priority_queue<int, vector<int>, greater<>> q;
        for (int i = 0; i < n; i++) {
            q.push(capacity[i] - rocks[i]);
        }

        int i = 0, fullBags = 0;
        while (additionalRocks > 0 && i < n) {
            additionalRocks -= q.top(); // O(1)
            q.pop(); // nlog(n)
            if (additionalRocks >= 0) {
                fullBags++;
            }
            i++;
        }

        return fullBags;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> capacity = vector<int>{2, 3, 4, 5};
    vector<int> rocks = vector<int>{1, 2, 4, 4};
    cout << s->maximumBagsC2(capacity, rocks, 2);
    return 0;
}