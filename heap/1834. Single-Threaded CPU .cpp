#include "../stdc++.h"

// pair: <index, processingTime>
typedef pair<int, int> pp;

struct Compare {
    bool operator()(const pp &a, const pp &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

struct SortCompare {
    inline bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int currTime, n = tasks.size(), index = 0;
        vector<int> rs;

        vector<vector<int>> tasksWithIndex(n);
        for (int i = 0; i < n; i++) {
            tasksWithIndex[i] = vector<int>{tasks[i][0], i};
        }
        priority_queue<pp, vector<pp>, Compare> availableTasks;

        sort(tasks.begin(), tasks.end(), SortCompare());
        sort(tasksWithIndex.begin(), tasksWithIndex.end(), SortCompare());

        currTime = tasks[0][0];

        while (index < n) {
            // Find the available tasks
            while (index < n && currTime >= tasks[index][0]) {
                availableTasks.push({tasksWithIndex[index][1], tasks[index][1]});
                index++;
            }

            //
            if (availableTasks.empty()) {
                currTime = tasks[index][0];
                continue;
            }

            // Processing Tasks
            auto t = availableTasks.top();
            availableTasks.pop();

            rs.push_back(t.first); // Push index
            currTime += t.second; // Increase current time
        }

        while (!availableTasks.empty()) {
            auto t = availableTasks.top();
            availableTasks.pop();
            rs.push_back(t.first); // Push index
        }

        return rs;
    }
};

// [[5,2],[7,2],[9,4],[6,3],[5,10],[1,1]]
int main() {
    Solution *s = new Solution();
    auto tasks = vector<vector<int>>{
            {5, 2},
            {7, 2},
            {9, 4},
            {6, 3},
            {5, 10},
            {1, 1},
    };
    auto rs = s->getOrder(tasks);
}