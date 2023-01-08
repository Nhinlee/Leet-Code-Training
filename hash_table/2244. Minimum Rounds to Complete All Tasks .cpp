#include "../stdc++.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int count = 0;
        map<int, int> tasksMap;
        for(auto x : tasks) {
            tasksMap[x]++;
        }

        for (auto it : tasksMap) {
            if (it.second == 1) return -1;
            count += ceil(it.second / 3.0);
        }

        return count;
    }
};
//
//int main() {
//    Solution *s = new Solution();
//    auto tasks = vector<int> {2,2,3,3,2,4,4,4,4,4};
//    cout << s->minimumRounds(tasks);
//}