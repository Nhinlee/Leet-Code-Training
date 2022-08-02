#include "../stdc++.h"

class Solution {
public:
    int countDistinct(vector<int> &nums, int k, int p) {
        int rs = 0;
        map<string, int> flags;
        for (int i = 0; i < nums.size(); i++) {
            int j = i, countK = 0;
            string temp = "";
            while (countK <= k && j < nums.size()) {
                temp += to_string(nums[j]) + ".";

                if (countK <= k && flags[temp] == 0) rs++;
                if (nums[j] % p == 0) countK++;

                flags[temp]++;
                j++;
            }
        }

        return rs;
    }
};