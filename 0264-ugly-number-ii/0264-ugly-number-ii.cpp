class Solution {
public:
    int nthUglyNumber(int n) {
        queue<int> mq;
        mq.push(1);
        unordered_set<int> visited;
        visited.insert(1);
        while (!mq.empty()) {
            long long num = (long long)mq.front();
            mq.pop();
            for (int x : {2, 3, 5}) {
                if (num*x > INT_MAX) {
                    continue;
                }
                if (visited.count(num*x)) {
                    continue;
                }
                visited.insert(num*x);
                mq.push(num*x);
            }
        }
        vector<int> v(visited.begin(), visited.end());
        sort(v.begin(), v.end());
        return v[n - 1];
    }
};