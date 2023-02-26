class RecentCounter {
private:
    queue<int> mq;
    
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        mq.push(t);
        while (mq.front() < t - 3000) {
            mq.pop();
        }
        return mq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */