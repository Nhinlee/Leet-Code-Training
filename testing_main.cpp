#include "stdc++.h"

// https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int i = 0, j = 0, n = nums.size(), count = 0, rs = 0;

        //
        while (j < n) {
            if (nums[j] == 0) count++;
            if (count > k + 1) break;
            j++;
        }
        if (count <= k) return n;
        while (i < n && nums[i] != 0) i++;

        //
        while (i < n) {
            rs = max(rs, j - i - 1);

            i++;
            j++;
            while (i < n && nums[i] != 0) i++;
            while (j < n && nums[j] != 0) j++;
        }

        return rs;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << s->longestOnes(nums, 1);
}