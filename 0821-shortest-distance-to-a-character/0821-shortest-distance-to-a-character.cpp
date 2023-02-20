class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        queue<int> mq;
        const int n = s.size();
        vector<int> dist(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                mq.push(i);
            }
        }
        while (!mq.empty()) {
            int m = mq.size();
            while (m--) {
                int i = mq.front();
                mq.pop();
                int r = i + 1;
                int l = i - 1;
                if (0 <= l and l < n and s[l] != c and dist[l] == 0) {
                    dist[l] = 1 + dist[i];
                    mq.push(l);
                }
                if (0 <= r and r < n and s[r] != c and dist[r] == 0) {
                    dist[r] = 1 + dist[i];
                    mq.push(r);
                }
            }
        }
        return dist;
    }
};