class MyCalendarThree {
private:
    map<int, int> line;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;
        int res = 0, numBook = 0;
        for (auto [_, book] : line) {
            numBook += book;
            res = max(res, numBook);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */