#include "../stdc++.h"

class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }

    // C1: Sort x start
    int findMinArrowShots(vector<vector<int>> &points) {
        // sort points
        sort(points.begin(), points.end(), compare);

        // loop to count arrows
        int arrows = 1, minX = points[0][0], maxX = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] >= minX && points[i][0] <= maxX) {
                // Case : 1
                // [---------]
                //   [---------]
                // Case : 2
                // [---------]
                //   [-----]
                minX = points[i][0];
                maxX = min(points[i][1], maxX);
            } else {
                // Case : 3
                // [----]
                //        [-----]
                minX = points[i][0];
                maxX = points[i][1];
                arrows++;
            }
        }

        return arrows;
    }

    static bool compareLast(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    // C2: Optimization: sort x end
    int findMinArrowShotsC2(vector<vector<int>> &points) {
        // sort points
        sort(points.begin(), points.end(), compareLast);

        // loop to count arrows
        int arrows = 1;
        vector<int> last = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= last[1]) {
                // Case : 1
                // [---------]
                //   [---------]
                // Case : 2
                // [---------]
                //   [-----]
                continue;
            } else {
                // Case : 3
                // [----]
                //        [-----]
                last = points[i];
                arrows++;
            }
        }

        return arrows;
    }
};