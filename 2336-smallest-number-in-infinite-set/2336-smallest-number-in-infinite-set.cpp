class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> us;
    
public:
    SmallestInfiniteSet() {
        for (int val = 1; val <= 1000; ++val) {
            pq.push(val);
            us.insert(val);
        }
    }
    
    int popSmallest() {
        int val = pq.top();
        pq.pop();
        us.erase(val);
        return val;
    }
    
    void addBack(int num) {
        if (us.count(num)) {
            return;
        }
        pq.push(num);
        us.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */