#include "../stdc++.h"


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