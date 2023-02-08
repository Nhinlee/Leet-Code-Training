#include "../stdc++.h"

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() <= 1) return 0;

        queue<int> q;
        vector<int> jumps(nums.size(), INT_MAX);
        int steps = 0;
        q.push(0);
        jumps[0] = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                for (int i = curr + nums[curr]; i > curr; i--) {
                    if (i >= nums.size() - 1) {
                        return steps + 1;
                    }
                    if (jumps[i] == INT_MAX) {
                        jumps[i] = steps + 1;
                        q.push(i);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};