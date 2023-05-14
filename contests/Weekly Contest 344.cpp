#include "../stdc++.h"

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        vector<int> rs;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            rs.push_back(countDict(nums, 0, i + 1) - countDict(nums, i + 1, n) + 1);
        }

        return rs;
    }

    int countDict(vector<int> &nums, int i, int j) {
        vector<bool> flag(50);
        int c = 0;
        for (; i < j; i++) {
            if (!flag[nums[i]]) {
                c++;
                flag[nums[i]] = true;
            }
        }

        return c;
    }

    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        vector<int> colors(n), rs;
        int index, co;
        int count = 0;

        for (auto q: queries) {
            index = q[0];
            co = q[1];

            if (colors[index] != co) {
                if (index > 0) {
                    if (colors[index] == colors[index - 1] && colors[index] != 0) {
                        count = max(count - 1, 0);
                    } else if (co == colors[index - 1]) {
                        count++;
                    }
                }

                if (index < n - 1) {
                    if (colors[index] == colors[index + 1] && colors[index] != 0) {
                        count = max(count - 1, 0);
                    } else if (co == colors[index + 1]) {
                        count++;
                    }
                }
            }

            colors[index] = co;
            rs.push_back(count);
        }

        return rs;
    }
};

//int main() {
//    vector<vector<int>> nums = {{0, 2},
//                                {1, 2},
//                                {3, 1},
//                                {1, 1},
//                                {2, 1}};
//    vector<int> d = vector<int>{7, 4};
//    string t = "aaaaab";
//    Solution *s = new Solution();
//    s->colorTheArray(4, nums);
//
//    return 0;
//}

class FrequencyTracker {
    map<int, int> nums, frequencies;
public:
    FrequencyTracker() {

    }

    void add(int n) {
        if (nums[n] > 0) {
            frequencies[nums[n]]--;
        }
        nums[n]++;
        frequencies[nums[n]]++;
    }

    void deleteOne(int n) {
        if (nums[n] > 0) {
            frequencies[nums[n]]--;
            nums[n]--;
            frequencies[nums[n]]++;
        }
    }

    bool hasFrequency(int f) {
        return frequencies[f] > 0;
    }
};