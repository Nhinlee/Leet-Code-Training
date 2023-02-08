#include "../stdc++.h"

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        map<int, int> flags;
        int n = fruits.size(), baskets = 0, maxL = 0, currL = 0;

        // For loop to get first flags
        int i = 0;
        while (i < n) {
            if (flags[fruits[i]] == 0) {
                if (baskets == 2) break;
                baskets++;
            }
            flags[fruits[i]]++;
            maxL++;
            i++;
        }

        // Check special cases
        if (baskets == 1) return n;

        // Sliding window to get max length
        int j = 0;
        currL = maxL;
        while (i < n) {

            while (j < i) {
                flags[fruits[j]]--;
                currL--;
                j++;
                if (flags[fruits[j - 1]] == 0) {
                    baskets--;
                    break;
                }
            }

            while (i < n) {
                if (flags[fruits[i]] == 0 && baskets == 2) break;
                if (flags[fruits[i]] == 0) baskets++;
                flags[fruits[i]]++;
                currL++;
                i++;
            }

            maxL = max(maxL, currL);
        }

        return maxL;
    }

    // C2:
    int totalFruitC2(vector<int>& fruits) {
        unordered_map<int, int> count;
        int start = 0, end = 0, max_len = 0;
        while (end < fruits.size()) {
            count[fruits[end]]++;
            while (count.size() > 2) {
                count[fruits[start]]--;
                if (count[fruits[start]] == 0) {
                    count.erase(fruits[start]);
                }
                start++;
            }
            max_len = max(max_len, end - start + 1);
            end++;
        }
        return max_len;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> f = vector<int>({0,1,2,2});
    cout<<s->totalFruit(f);
}