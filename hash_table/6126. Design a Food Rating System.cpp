#include "../stdc++.h"


typedef pair<int, string> Food;

class FoodRatings {

    map<string, set<Food>> menu;
    map<string, string> food_cuisines;
    map<string, int> foodsMap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            menu[cuisines[i]].insert(Food{-ratings[i], foods[i]});
            food_cuisines[foods[i]] = cuisines[i];
            foodsMap[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        auto cuisines = food_cuisines[food];
        auto oldRating = foodsMap[food];
        menu[cuisines].erase(Food{-oldRating, food});
        menu[cuisines].insert(Food{-newRating, food});
        foodsMap[food] = newRating;
    }

    string highestRated(string cuisine) {
        return menu[cuisine].begin()->second;
    }
};