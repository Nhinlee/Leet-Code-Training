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
//    vector<string> foods{"emgqdbo", "jmvfxjohq", "qnvseohnoe", "yhptazyko", "ocqmvmwjq"};
//    vector<string> cuisines{"snaxol", "snaxol", "snaxol", "fajbervsj", "fajbervsj"};
//    vector<int> ratings{9, 13, 7, 16, 10, 17, 16, 17};
//    FoodRatings *f = new FoodRatings(foods, cuisines, ratings);
//    f->changeRating("qnvseohnoe", 11);
//    f->highestRated("fajbervsj");
//    f->changeRating("emgqdbo", 3);
//    f->changeRating("jmvfxjohq", 9);
//    f->changeRating("emgqdbo", 14);
//    f->highestRated("fajbervsj");
//    f->highestRated("snaxol");
//}