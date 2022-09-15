#include "stdc++.h"

// https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int i = 0, j = 0, n = nums.size(), count = 0, rs = 0;

        //
        while (j < n) {
            if (nums[j] == 0) count++;
            if (count > k + 1) break;
            j++;
        }
        if (count <= k) return n;
        while (i < n && nums[i] != 0) i++;

        //
        while (i < n) {
            rs = max(rs, j - i - 1);

            i++;
            j++;
            while (i < n && nums[i] != 0) i++;
            while (j < n && nums[j] != 0) j++;
        }

        return rs;
    }

    char repeatedCharacter(string s) {
        vector<int> flags(26, 0);
        for (auto c: s) {
            flags[c - 'a']++;
            if (flags[c - 'a'] > 1) return c;
        }
        return 'a';
    }

    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size(), rs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (equalPairs(grid, i, j)) rs++;
            }
        }
        return rs;
    }

    bool equalPairs(vector<vector<int>> &grid, int i, int j) {
        for (int k = 0; k < grid.size(); k++) {
            if (grid[i][k] != grid[k][j]) return false;
        }
        return true;
    }

    void performOperations(vector<int> &arr, vector<vector<int>> &operations) {
        for (auto o: operations) {
            reverseArr(arr, o[0], o[1]);
        }
    }

    void reverseArr(vector<int> &arr, int i, int j) {
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    int stockPairs(vector<int> &stockProfits, int target) {
        map<int, int> flags;
        vector<int> sets(stockProfits.size(), 0);
        int rs = 0;

        for (auto s: stockProfits) {
            flags[s]++;
        }

        for (auto s: stockProfits) {
            if (flags[target - s] > 0 && sets[s] == 0 && sets[target - s] == 0) {
                sets[s]++;
                sets[target - s]++;
                rs++;
            }
        }

        return rs;
    }

    int stockPairsV2(vector<int> &stockProfits, int target) {
        map<int, int> flags;
        int rs = 0;

        for (auto s: stockProfits) {
            flags[s]++;
        }

        for (auto s: stockProfits) {
            if (flags[target - s] > 0) {
                rs++;
            }
        }

        return rs / 2;
    }

    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        vector<vector<int>> rs;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i <= n - 3; i++) {
            rs.push_back(vector<int>());
            for (int j = 0; j <= m - 3; j++) {
                int maxx = 0;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        maxx = max(grid[k][l], maxx);
                    }
                }
                rs[i].push_back(maxx);
            }
        }
        return rs;
    }

    int edgeScore(vector<int> &edges) {
        map<int, long> scores;
        for (int i = 0; i < edges.size(); i++) {
            scores[edges[i]] += i;
        }
        long maxx = 0, maxIndex = 0;
        for (auto it: scores) {
            if (it.second > maxx) {
                maxx = it.second;
                maxIndex = it.first;
            }
        }
        return maxIndex;
    }

    string smallestNumber(string pattern) {
        string smallestNum = "1";
        char maxDigit = '1';
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'D') {
                smallestNum.push_back(smallestNum[i] - 1);
                int j = i;
                while (j >= 0 && pattern[j] != 'I') {
                    smallestNum[j + 1]++;
                    j--;
                }
                smallestNum[j + 1]++;
            } else {
                smallestNum.push_back(maxDigit + 1);
            }
            maxDigit++;
        }
        return smallestNum;
    };

    // Leet code - Weekly Contest 309
    bool checkDistances(string s, vector<int> &distance) {
        vector<int> sdis(distance.size());
        vector<bool> appears(distance.size());
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            appears[index] = true;

            if (sdis[index] == 0) {
                sdis[index] = i + 1;
            } else {
                sdis[index] = i - sdis[index];
            }
        }

        for (int i = 0; i < sdis.size(); i++) {
            if (appears[i] && sdis[i] != distance[i]) return false;
        }
        return true;
    }

    int longestNiceSubarray(vector<int> &nums) {
        int n = nums.size(), currLength = 1, sum = nums[0];
        int maxNiceLength = 1;

        for (int i = 1; i < n; i++) {
            currLength++;
            if ((sum & nums[i]) == 0) {
                maxNiceLength = max(currLength, maxNiceLength);
            } else {
                while (currLength > 1 && (sum & nums[i]) != 0) {
                    sum ^= nums[i - currLength + 1];
                    currLength--;
                }
            }
            sum |= nums[i];
        }

        return maxNiceLength;
    }

    int numberOfWays(int startPos, int endPos, int k) {
    }
};

typedef pair<string, int> Food;

struct foodCMP {
    bool operator()(const Food a, const Food b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    }
};

class FoodRatings {

    map<string, set<Food, foodCMP>> menu;
    map<string, string> food_cuisines;
    map<string, int> foodsMap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            menu[cuisines[i]].insert(Food{foods[i], ratings[i]});
            food_cuisines[foods[i]] = cuisines[i];
            foodsMap[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        auto cuisines = food_cuisines[food];
        auto oldRating = foodsMap[food];
        menu[cuisines].erase(Food{food, oldRating});
        menu[cuisines].insert(Food{food, newRating});
        foodsMap[food] = newRating;
    }

    string highestRated(string cuisine) {
        return menu[cuisine].begin()->first;
    }
};

//int main() {
//    Solution *s = new Solution();
//    vector<int> arr{1, 3, 8, 48, 10};
//    cout << s->longestNiceSubarray(arr);
//}