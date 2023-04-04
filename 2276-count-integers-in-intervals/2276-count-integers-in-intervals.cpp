class CountIntervals {
private:
    unordered_map<int, int> tree;
    
public:
    CountIntervals() {
        
    }
    
    void update(int id, int left, int right, int qLeft, int qRight) {
        if (qLeft > right or qRight < left) {
            return;
        }
        if (qLeft <= left and right <= qRight) {
            tree[id] = right - left + 1;
            return;
        }
        int mid = left + (right - left) / 2;
        update(2 * id, left, mid, qLeft, qRight);
        update(2 * id + 1, mid + 1, right, qLeft, qRight);
        tree[id] = max(tree[id], tree[id * 2] + tree[id * 2 + 1]);
    }
    
    void add(int left, int right) {
        update(1, 1, 1e9, left, right);
    }
    
    int count() {
        return tree[1];
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */