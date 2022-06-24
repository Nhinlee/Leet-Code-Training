#include "../stdc++.h"

class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        int n = nums.size();
        vector<int> rs(n, pivot);

        int i = 0, j = n - 1;
        for (int k = 0, l = n - 1; k < nums.size() && l >= 0; k++, l--) {
            if (nums[k] < pivot) rs[i++] = nums[k];
            if (nums[l] > pivot) rs[j--] = nums[l];
        }

        return rs;
    }

    int minimumCeli(int n, vector<int> &a, int s) {
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, a[i]);
        }

        int l = 1, r = maxx, mid;
        while (l < r) {
            mid = (l + r) / 2;
            int temp = sumCeli(a, mid);
            if (temp == s) return mid;
            if (temp > s) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return (l + r) / 2;
    }

    int sumCeli(vector<int> &a, int d) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += ceil(a[i] / (d * 1.0));
        }
        return sum;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << s->minimumCeli(11, arr, 100);
}