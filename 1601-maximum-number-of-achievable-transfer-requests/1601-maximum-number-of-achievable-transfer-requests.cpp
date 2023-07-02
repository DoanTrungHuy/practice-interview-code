class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        int m = requests.size();
        for (int mask = 1; mask < (1 << m); ++mask) {
            vector<int> degree(n);
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    int u = requests[i][0];
                    int v = requests[i][1];
                    degree[u]--;
                    degree[v]++;
                    cnt++;
                }
            }
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (degree[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};