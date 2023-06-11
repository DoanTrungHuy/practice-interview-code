class SnapshotArray {
private:
    map<int, map<int, int>> camera;
    int snap_id = 0;
    
public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; ++i) {
            map<int, int> mp;
            mp[0] = 0;
            camera[i] = mp;
        }
    }
    
    void set(int index, int val) {
        camera[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = camera[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */