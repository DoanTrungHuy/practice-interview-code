class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        large.push(num);
        small.push(large.top());
        large.pop();
        if (large.size() < small.size()) {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return (double)(small.top() + large.top()) / 2;
        }
        return large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */