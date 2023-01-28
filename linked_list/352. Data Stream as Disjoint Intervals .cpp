#include "../stdc++.h"

// C1: Using List
class SummaryRanges {
    list<int> nums;
public:
    SummaryRanges() {}

    void addNum(int value) {
        if (nums.size() == 0) {
            nums.push_back(value);
        } else {
            auto it = nums.begin();
            for (; it != nums.end(); it++) {
                if (value <= *it) {
                    nums.insert(it, value);
                    return;
                }
            }

            if (it == nums.end()) {
                nums.push_back(value);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> rs;
        if (nums.empty()) return rs;

        auto it = nums.begin();
        vector<int> curr = {*it, *it};
        rs.push_back(curr);
        int i = 0;
        it++;

        for (; it != nums.end(); it++) {
            if (*it - curr[1] <= 1) {
                curr[1] = *it;
                rs[i][1] = *it;
            } else {
                curr = {*it, *it};
                rs.push_back(curr);
                i++;
            }
        }

        return rs;
    }
};


// C2: Using Map
class SummaryRangesC2 {
    map<int, int> intervals;

public:
    SummaryRangesC2() {}

    void addNum(int value) {
        int left = value, right = value;
        auto small_entry = intervals.upper_bound(value);
        if (small_entry != intervals.begin()) {
            auto max_entry = small_entry;
            --max_entry;
            if (max_entry->second >= value) {
                return;
            }
            if (max_entry->second == value - 1) {
                left = max_entry->first;
            }
        }
        if (small_entry != intervals.end() && small_entry->first == value + 1) {
            right = small_entry->second;
            intervals.erase(small_entry);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for (const auto& p : intervals) {
            answer.push_back({p.first, p.second});
        }
        return answer;
    }
};