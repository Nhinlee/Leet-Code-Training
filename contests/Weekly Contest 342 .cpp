#include "../stdc++.h"

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }

    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) sum += i;
        }
        return sum;
    }

    // Sliding window
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        vector<int> flags(101);
        vector<int> rs;
        int n = nums.size();

        //
        int i = 0;
        for (i = 0; i < k; i++) {
            flags[nums[i] + 50]++;
        }

        rs.push_back(findSmallestX(flags, x));

        for (; i < n; i++) {
            flags[nums[i] + 50]++;
            flags[nums[i - k] + 50]--;
            rs.push_back(findSmallestX(flags, x));
        }

        return rs;
    }

    int findSmallestX(vector<int> &flags, int x) {
        int c = 0;
        for (int i = 0; i < 50; i++) {
            c += flags[i];
            if (c >= x) return i - 50;
        }
        return 0;
    }

    // 6392. Minimum Number of Operations to Make All Array Elements Equal to 1
    int minOperations(vector<int> &nums) {
        // ????????
    }
};

//int main() {
//    vector<int> nums = vector<int>{10,5,10,30,70,4,2,6,8,4};
//    vector<int> d = vector<int>{7, 4};
//    string t = "aaaaab";
//    Solution *s = new Solution();
//    cout << s->minOperations(nums);
//
//    return 0;
//}