#include "../stdc++.h"

typedef pair<int, int> Meeting;

class MyCalendar {
private:
    vector<Meeting> meetings;
public:
    MyCalendar() {
        meetings = vector<Meeting>();
    }

    bool book(int start, int end) {
        for (auto m: meetings) {
            if (max(m.first, start) < min(m.second, end)) return false;
        }
        meetings.emplace_back(start, end);
        return true;
    }
};

class MyCalendar2 {
private:
    set<Meeting> meetings;
public:
    MyCalendar2() {
        meetings = set < Meeting > ();
    }

    bool book(int start, int end) {
        auto it = meetings.lower_bound({start, end});

        if (it != meetings.end() && it->first < end) return false;
        if (it != meetings.begin() && start < (--it)->second) return false;

        meetings.insert({start, end});

        return true;
    }
};