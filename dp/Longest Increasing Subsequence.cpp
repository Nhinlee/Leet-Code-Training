#include "../stdc++.h"

class Solution {
public:
    // C1: Recursive
    int lengthOfLIS(vector<int> &arr) {
        int longest = 1;
        _lengthOfLIS(arr, arr.size(), longest);
        return longest;
    }

    int _lengthOfLIS(vector<int> &arr, int n, int &currentLongest) {

        if (n == 1) return 1;

        int longest = 1;
        for (int j = 1; j < n; j++) {
            int temp = _lengthOfLIS(arr, j, currentLongest);
            if (arr[j - 1] < arr[n - 1]) {
                longest = max(longest, 1 + temp);
            }
        }

        currentLongest = max(currentLongest, longest);

        return longest;
    }

};

//int main() {
//    Solution *s = new Solution();
//    vector<int> arr{2, 4, 6, 3, 5, 3, 1};
//    cout << s->lengthOfLIS(arr);
//}