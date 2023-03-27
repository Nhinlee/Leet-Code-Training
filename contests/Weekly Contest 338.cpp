#include "../stdc++.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) return k;
        if (k <= (numOnes + numZeros)) return numOnes;
        return numOnes - min(k - (numOnes + numZeros), numNegOnes);
    }

    vector<bool> generatePrimeArr(int n) {
        n++;
        vector<bool> primes(n, true);

        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (j % i == 0) {
                        primes[j] = false;
                    }
                }
            }
        }

        return primes;
    }

    bool primeSubOperation(vector<int> &nums) {
        auto primes = generatePrimeArr(1000);

        int d = nums[0] - 1;
        while (d > 0 && !primes[d]) d--;
        nums[0] -= d;

        for (int i = 1; i < nums.size(); i++) {
            d = nums[i] - 1;

            while (nums[i] - d <= nums[i - 1] || !primes[d]) {
                if (d == 0) break;
                d--;
            }

            nums[i] -= d;

            if (nums[i] <= nums[i-1]) return false;
        }

        return true;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{20,14,14,1};
    cout << s->primeSubOperation(nums);
}