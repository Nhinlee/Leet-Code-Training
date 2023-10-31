#include "../stdc++.h"

class SnapshotArray {
private:
    int snapId;
    vector<set<int>> data;

public:
    SnapshotArray(int length) {
        snapId = 0;
        data[0] = {};
    }

    void set(int index, int val) {
        data[snapId].insert(val);
    }

    int snap() {
        snapId++;
    }

    int get(int index, int snap_id) {

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */