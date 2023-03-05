class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < n; ++i) {
            um[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        queue<int> mq;
        mq.push(0);
        visited[0] = true;
        int step = 0;
        while (!mq.empty()) {
            int m = mq.size();
            while (m--) {
                int i = mq.front();
                mq.pop();
                if (i == n - 1) {
                    return step;
                }
                vector<int> &next = um[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                for (int j : next) {
                    if (0 <= j and j < n and !visited[j]) {
                        visited[j] = true;
                        mq.push(j);
                    }
                }
                next.clear();
            }
            step += 1;
        }
        return 0;
    }
};