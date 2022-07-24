#include "../stdc++.h"

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        arr.insert(arr.begin(), 0);
        int n = arr.size(), rs = 0;
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }

        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (arr[i] == arr[k]) rs += k - i - 1;
            }
        }

        return rs;
    }
};
//
//int main() {
//    Solution *s = new Solution();
//    vector<int> arr{2, 3, 1, 6, 7};
//    cout << s->countTriplets(arr);
//}
