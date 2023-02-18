#include "../stdc++.h"

class Solution {
public:
    // https://leetcode.com/contest/weekly-contest-332/problems/find-the-array-concatenation-value/
    long long findTheArrayConcVal(vector<int> &nums) {
        long long conc = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (i == j) {
                conc += nums[i];
                return conc;
            }
            conc += concOf(nums[i], nums[j]);
            i++;
            j--;
        }

        return conc;
    }

    long long concOf(int a, int b) {
        long long conc = a;
        string rb = "";
        while (b > 0) {
            char temp = b % 10 + '0';
            rb = temp + rb;
            b /= 10;
        }

        for (auto c: rb) {
            conc *= 10;
            conc += (c - '0') % 10;
        }

        return conc;
    }

    // https://leetcode.com/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/
    long long countFairPairs(vector<int> &nums, int lo, int up) {
        std::sort(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int upIndex = binarySearchUp(nums, i, n - 1, up - x);
            int lowerIndex = binarySearchLower(nums, i + 1, n - 1, lo - x);
            if (upIndex < lowerIndex) continue;
            if (nums[upIndex] + nums[i] < lo) continue;
            if (nums[lowerIndex] + nums[i] > up) continue;

            sum += upIndex - lowerIndex + 1;
        }

        return sum;
    }

    int binarySearchUp(vector<int> &nums, int l, int r, int x) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }

    int binarySearchLower(vector<int> &nums, int l, int r, int x) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums = vector<int>{5, 7, 5, 7, 5};

    cout << s->countFairPairs(nums, 12, 12);
}

//[6,9,4,2,7,5,10,3]
//13
//13
//[5,7,5,7,5]
//12
//12