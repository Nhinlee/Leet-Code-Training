#include "../stdc++.h"

class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;

        for (auto g: gifts) {
            pq.push(g);
            sum += g;
        }

        while (k-- > 0) {
            int m = pq.top();
            pq.pop();

            sum -= m - sqrt(m);
            pq.push(sqrt(m));
        }

        return sum;
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        int n = words.size();
        vector<int> flags(n);

        flags[0] = isVowelWord(words[0]) ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (isVowelWord(words[i])) {
                flags[i] = flags[i - 1] + 1;
            } else {
                flags[i] = flags[i - 1];
            }
        }

        vector<int> rs;
        for (auto q: queries) {
            int i = q[0], j = q[1];
            int totalV = flags[j] - flags[i];
            if (isVowelWord(words[i])) totalV++;
            rs.push_back(totalV);
        }

        return rs;
    }

    bool isVowelWord(string w) {
        return isVowel(w[0]) && isVowel(w[w.size() - 1]);
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int minCapability(vector<int> &A, int k) {
        int left = 1, right = 1e9, n = A.size();
        while (left < right) {
            int mid = (left + right) / 2, take = 0;
            for (int i = 0; i < n; ++i)
                if (A[i] <= mid) {
                    take += 1;
                    i++;
                }
            if (take >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left; //left == right
    }

    long long minCost(vector<int>& A, vector<int>& B) {
        map<int, int> count;
        for (int a : A)
            ++count[a];
        for (int a : B)
            --count[a];
        vector<long long> swaps;
        long long res = 0, small = begin(count)->first;
        for (auto [a, v] : count) {
            if (v % 2) return -1;
            for (int i = 0; i < abs(v) / 2; ++i)
                swaps.push_back(a);
        }
        for (int i = 0; i < swaps.size() / 2; ++i)
            res += min(swaps[i], small * 2);
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> a = vector<int>{2,2,4,2,2,2};
    vector<int> b = vector<int>{3,3,3,4,3,2};

    cout << s->minCost(a, b);
}