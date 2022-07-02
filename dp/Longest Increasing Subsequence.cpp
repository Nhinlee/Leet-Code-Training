#include "../stdc++.h"

class Solution {
public:
    // C1:
    int longestIncreasingSubsequence(vector<int> &arr, int i) {

        int longest = 0;
        for (int j = i + 1; j < arr.size(); j++) {
            int temp = longestIncreasingSubsequence(arr, j);
            if (arr[j] >= arr[i]) {
                longest = max(longest, 1 + temp);
            } else {
                longest = max(longest, temp);
            }
        }

        return longest;
    }

    // C2:
    int longestIncreasingSubsequenceC2(vector<int> &arr, int i) {

        int longest = 0;
        for (int j = i - 1; j >= 0; j--) {
            int temp = longestIncreasingSubsequenceC2(arr, j);
            if (arr[j] <= arr[i]) {
                longest = max(longest, 1 + temp);
            } else {
                longest = max(longest, temp);
            }
        }

        return longest;
    }

    // C3: DP
    int longestIncreasingSubsequenceC3(vector<int> &arr) {

    }
};

int main() {
    Solution *s = new Solution();
    vector<int> arr{2, 4, 6, 3, 5, 3, 1};
    cout << s->longestIncreasingSubsequence(arr, 0);
}