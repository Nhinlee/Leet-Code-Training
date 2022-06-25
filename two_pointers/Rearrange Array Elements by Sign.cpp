#include "../stdc++.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        int posIndex = 0, nevIndex = 0;
        int n = nums.size();
        vector<int> rs;
        while (nums[posIndex] <= 0) posIndex++;
        while (nums[nevIndex] >= 0) nevIndex++;

        while (posIndex < n && nevIndex < n) {
            rs.push_back(nums[posIndex]);
            rs.push_back(nums[nevIndex]);

            posIndex++;
            nevIndex++;
            while (posIndex < n && nums[posIndex] <= 0) posIndex++;
            while (nevIndex < n && nums[nevIndex] >= 0) nevIndex++;
        }

        return rs;
    }

    vector<int> rearrangeArrayC2(vector<int> &nums) {
        vector<int> rs(nums.size(), 0);
        int posIndex = 0, nevIndex = 1;
        for (auto x: nums) {
            if (x > 0) {
                rs[posIndex] = x;
                posIndex += 2;
            } else {
                rs[nevIndex] = x;
                nevIndex += 2;
            }
        }

        return rs;
    }
};
