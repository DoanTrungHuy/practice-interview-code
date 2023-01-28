class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        for (string deadend : deadends) {
            if (deadend == "0000") {
                return -1;
            }
        }
        unordered_set<string> us(deadends.begin(), deadends.end());
        queue<pair<string, int>> mq;
        unordered_set<string> visited;
        mq.push({"0000", 0});
        visited.insert("0000");
        while (!mq.empty()) {
            auto [lock, step] = mq.front();
            mq.pop();
            if (lock == target) {
                return step;
            }
            for (int i = 0; i < 4; ++i) {
                char tmp = lock[i];
                if (lock[i] == '9') {
                    lock[i] = '0';
                }
                else {
                    lock[i] += 1;
                }
                if (us.find(lock) == us.end() and visited.find(lock) == visited.end()) {
                    mq.push({lock, step + 1});
                    visited.insert(lock);
                }
                lock[i] = tmp;
            }
            for (int i = 0; i < 4; ++i) {
                char tmp = lock[i];
                if (lock[i] == '0') {
                    lock[i] = '9';
                }
                else {
                    lock[i] -= 1;
                }
                if (us.find(lock) == us.end() and visited.find(lock) == visited.end()) {
                    mq.push({lock, step + 1});
                    visited.insert(lock);
                }
                lock[i] = tmp;
            }
        }
        return -1;
    }
};