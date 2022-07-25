#include "../stdc++.h"

class Solution {
    int maxx = 1000000007;
public:
    // C1: nlog(n)
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};

        int pos = bsFindPosition(nums, target);
        nums.push_back(maxx);
        if (pos == -1) return vector<int>{-1, -1};

        int i = pos, j = pos;
        while (j < nums.size() && nums[j] == target) j++;

        return vector<int>{i, j - 1};
    }

    int bsFindPosition(vector<int> &num, int target) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (num[mid] < target) l = mid + 1; else r = mid - 1;
        }

        return num[l] == target ? l : -1;
    }

    // C2: log(n)
    vector<int> searchRangeC2(vector<int> &nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};

        int leftPos = bsLeftPos(nums, target);
        if (leftPos == -1) return vector<int>{-1, -1};
        int rightPos = bsRightPos(nums, leftPos, target);

        return vector<int>{leftPos, rightPos};
    }

    int bsLeftPos(vector<int> &num, int target) {
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] < target) l = mid + 1; else r = mid - 1;
        }

        if (l >= num.size()) return -1;
        return num[l] == target ? l : -1;
    }


    int bsRightPos(vector<int> &num, int l, int target) {
        int r = num.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] > target) r = mid - 1; else l = mid + 1;
        }

        return r;
    }

};